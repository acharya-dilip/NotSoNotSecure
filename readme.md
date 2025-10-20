

# NotSoNotSecure
This is a custom messaging app built completely on C using libcurl8 and gtk4 and uses google sheet to store data
<br>
You send you message it gets stored in a faraway place where your peers or friends can signal to fetch that message to be displayed in their domain
# How to use?
- Login using your gmail and the app password
  (You can obtain your app password by going into manage your google account and searching it there and create a new one for this usage"
- Change your UserID if you want
- Press the 🔃 button to fetch the current messaege stored
- Type your message in the message entry
- Click send to replace the stored message by your message
# LIUNX BUILD INSTRUCTIONS

| FOR DEBIAN/UBUNTU                | For ARCH                    |      
|----------------------------------|-----------------------------|      
| Install Dependencies             | Install Dependencies        |      
| sudo apt install gtk             | sudo pacman -S gtk          |
| sudo apt install curl            | sudo pacman -S curl         |
| sudo apt install build-essential | sudo pacman -S base-devel   |
| sudo apt install cmake           | sudo pacman -S cmake        |

### Clone into the Github repo

| Command                                                       |
|---------------------------------------------------------------|
| git clone https://github.com/acharya-dilip/NotSoNotSecure.git |
### Navigate to project directory
| Command           |
|-------------------|
| cd NotSoNotSecure |
### Create the build directory
| Command  |
|--------------------------|
| mkdir build              |
### Navigate into the build directory
| Command   |
|----------------------------------|
| cd build                         |
###  Execute the Build Commands
| Commands   |
|----------------------------|
| cmake ..                   |
| cmake --build .            |

### Run the Program

| Command         |
|-----------------|
| .NotSoNotSecure |


