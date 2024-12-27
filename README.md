<p align="center"> <img src="https://img.shields.io/badge/Minishell-Linux%20Only-blue?style=for-the-badge" alt="Minishell Badge"> <img src="https://img.shields.io/github/stars/your-username/minishell?style=for-the-badge" alt="GitHub Stars Badge"> <img src="https://img.shields.io/badge/Made%20With-C%20Language-green?style=for-the-badge" alt="C Language Badge"> </p> <h1 align="center">🐚 Minishell</h1> <p align="center">A simplified shell project by <b>Armando Borges</b> & <b>Leonardo Jorge</b> 🛠️</p> <p align="center"> <img src="https://user-images.githubusercontent.com/placeholder/shell-terminal.png" alt="Shell Screenshot" width="700"> </p>
🌟 Introduction
The existence of shells is deeply connected to the history of computing itself. Back in the early days, developers communicated with computers using 1/0 switches, which was tedious and frustrating.

To simplify this interaction, shells were created: programs that interpret commands entered by users, enabling them to perform tasks in a more human-readable way.

With Minishell, you'll travel back in time and explore the challenges faced by developers before graphical interfaces (like Windows) existed. It's a hands-on experience with the foundations of modern computing.

🧰 Description
Minishell is a command-line interface (CLI) inspired by popular shells like Bash, Zsh, and Fish.

Here’s what you’ll learn by building or using it:

How a terminal works 🖥️
How commands are executed 🏗️
Environment variables and PATH 🗺️
Redirections and pipes 🔄
System-level programming concepts ⚙️
While this is a simplified version of a shell, it covers the essential features and mechanics, giving you a deeper understanding of Unix systems.

✨ Key Skills Gained
🔢 Algorithm Design
🧑‍💻 Interactive Programming
🐧 Unix System Programming
⚙️ Setup
Prerequisites
Ensure you have the following before getting started:

A Linux-based operating system 🐧
Required libraries and tools:
Dependencies for the readline library
The make utility
🚀 How to Compile
Clone the repository:
bash
Copiar código
git clone https://github.com/LeonardoDevelopper/minishell
cd minishell
Install dependencies:
bash
Copiar código
sudo apt-get install libreadline-dev make
Build the project:
bash
Copiar código
make
Run the shell:
bash
Copiar código
./minishell
📂 Project Structure
plaintext
Copiar código
minishell/
├── src/             # Source files
├── lib/             # Static libraries
├── include/         # Header files
├── Makefile         # Build script
└── README.md        # Project documentation
🐧 Usage Example
<p align="center"> <img src="https://user-images.githubusercontent.com/placeholder/demo.gif" alt="Shell Demo" width="600"> </p>
Once the shell is running, you can:

Navigate directories:

bash
Copiar código
cd /path/to/directory
List files:

bash
Copiar código
ls -l
Execute programs:

bash
Copiar código
echo "Hello, Minishell!"
Use redirections and pipes:

bash
Copiar código
echo "Hello" > file.txt | cat file.txt
🚧 Important Notes
This project is Linux-only.
The binary produced (minishell) is specific to Linux environments.
👥 Authors
<table> <tr> <td align="center"><a href="https://github.com/armando-borges"><img src="https://avatars.githubusercontent.com/u/placeholder?v=4" width="100px;" alt="Armando Borges"/><br /><sub><b>Armando Borges</b></sub></a></td> <td align="center"><a href="https://github.com/leonardo-jorge"><img src="https://avatars.githubusercontent.com/u/placeholder?v=4" width="100px;" alt="Leonardo Jorge"/><br /><sub><b>Leonardo Jorge</b></sub></a></td> </tr> </table>
Built with ❤️ for educational purposes.

📜 License
This project is licensed under the MIT License.