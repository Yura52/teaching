# Install Python

### Windows
1. Go to [https://www.python.org/downloads/windows/](https://www.python.org/downloads/windows/)
2. Choose "Latest Python 3 Release ..."
3. Scroll down and download "Windows x86-64 executable installer"
4. Install

### Linux, macOS
1. Go to https://conda.io/miniconda.html
2. Download Python 3.X which corresponds to your operating system (64-bit) **to the Desktop**
3. Open Terminal
4. Run "ls" (i.e. type "ls" and press "Enter") and find something like "Desktop"
5. Run "cd Desktop"
6. Run "ls"
7. Find something like "Miniconda3-....sh", let it be "Miniconda3-latest-MacOSX-x86_64.sh"
8. Run "bash Miniconda3-latest-MacOSX-x86_64.sh" and agree to all suggestions.
9. Close Terminal



# Install PyCharm Community Edition
Just visit [https://www.jetbrains.com/pycharm/download](https://www.jetbrains.com/pycharm/download) download and install. 



# Create a folder for your programs
Just a folder. Inside the folder you will gradually create folders for the contests. You will store your programs in these folders.

# Create your first program
1. Run PyCharm
2. *File* / *Open* / *\<the folder from the previous section\>*
3. *\<Right click on the folder at the left\>* / *New* / *Directory* / *"seminar_1"*
4. *\<Right click on the folder at the left\>* / *New* / *Python File* / *"hello_world"*
5. Put this text in the file: `print('Hello, World!')`
6. *Preferences* / *Project Interpreter* / \<path to the interpreter\>:  
Windows: something like "C:\python37"  
Linux: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;something like "/home/\<your login\>/miniconda3/bin/python"  
macOS: &nbsp;&nbsp;&nbsp;something like "/Users/\<your login\>/miniconda3/bin/python"  
(in Linux/macOS you can learn the path by opening Terminal and running "which python")
