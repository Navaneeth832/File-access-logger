#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/security.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Navaneeth");
MODULE_DESCRIPTION("File Access Logger Kernel Module");
MODULE_VERSION("1.0");

static int file_open_logger(struct file *file, const struct cred *cred) {
    pr_info("File Access: %s by UID: %d\n", file->f_path.dentry->d_name.name, cred->uid.val);
    return 0; // Allow file access
}

static struct security_operations file_logger_ops = {
    .file_open = file_open_logger,
};

static int __init file_logger_init(void) {
    if (register_security(&file_logger_ops)) {
        pr_err("Failed to register file access logger\n");
        return -1;
    }
    pr_info("File Access Logger Loaded\n");
    return 0;
}

static void __exit file_logger_exit(void) {
    unregister_security(&file_logger_ops);
    pr_info("File Access Logger Unloaded\n");
}

module_init(file_logger_init);
module_exit(file_logger_exit);
