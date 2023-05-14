# profile-changer
This is a program to switch profiles in programs that have a single settings file.
It will allow you to save the settings file in a seperate folder for each profile.
When you press launch it will load the settings file from the profile folder and launch the program. 
The program has a menu across the top. It will have file and settings options in the menu. 
File selections will be:
  * New profile
  * delete profile
  
The settings will be:
  * Light or dark mode - This should be a toggle
  * directory where the settings file is located for the program - this should be a browse box to select
  * executable for the program - this should be a browse box to select the file.

The main page will list the profiles. It should start with a temp profile that says delete me. This will help the user understand how to use the program.
When the user adds a profile it will create a folder to save the settings file in. THe user will be asked for a name for the profile. it will then grab the current settings file from the folder specified in the settings.
Each profile will have a launch and update option. 
The launch button should be larger and green. It will copy the settings file from the profile folder to the folder specified in settings and launch the executable specified in settings.
The update button should be smaller. When pressed it will copy the settings file from the folder specified in the settings menu to the profile folder.
