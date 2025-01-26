# File-access-logger
This project implements a Linux kernel module to log file access events on the system. It captures file open, read, and write operations and logs the details, such as the process ID, file path, and type of access, to the kernel ring buffer.

Features
Logs file access events (open, read, write) in the system.
Outputs log information to the kernel ring buffer (dmesg).
Simple and lightweight kernel module implementation.
Helps monitor file activity for debugging or security purposes.
Getting Started
Prerequisites
Linux environment with kernel development headers installed.
GCC compiler and Make utility.
Virtualization software (e.g., VirtualBox, VMware) with Ubuntu installed.
Basic understanding of kernel modules and dmesg.
Installation
Clone this repository:
bash
Copy
Edit
git clone https://github.com/<your-username>/file-access-logger.git
cd file-access-logger
Build the kernel module:
bash
Copy
Edit
make
Insert the module into the kernel:
bash
Copy
Edit
sudo insmod file_access_logger.ko
Verify that the module is loaded:
bash
Copy
Edit
lsmod | grep file_access_logger
Usage
View Logs
To view the file access logs, use the dmesg command:

bash
Copy
Edit
dmesg | grep "File Access Logger"
Remove the Module
To unload the kernel module:

bash
Copy
Edit
sudo rmmod file_access_logger
Clean the Build
To clean the compiled files:

bash
Copy
Edit
make clean
Files in the Repository
file_access_logger.c: Source code of the kernel module.
Makefile: Build instructions for compiling the kernel module.
README.md: Project documentation.
Contributing
Feel free to submit issues or contribute to the project by opening a pull request. Contributions are welcome!

License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments
Linux Kernel Module Programming Guide
Open-source kernel development resources
