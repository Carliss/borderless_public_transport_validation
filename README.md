# Borderless Public Transport Validation

### https://github.com/Carliss/borderless_public_transport_validation


## Description
This repository contains the files that was used to set up the prototype in the project course User Centered Design.

These files will not do any good without the full setup.

## File explanations
The repository contains one file called CCU.ino. This file is the code that was loaded on the arduino during the project.

The arduino.py file is a python file setting up a serial to read the output from the arduino.

The app.py file is a python file using Flask to serve a simple webpage where the "database" is showed.

The templates and static folders are used by the app.py file.

The requirements file contains every python package used to serve the website.


## Setup

1. load the CCU.ino script to the arduino  
2. connect the arduino to the computer with an usb cable
3. run the web server with `python app.py`
4. go to localhost:8888

Now the webserver should be listening to the output from the arduino, and show the validating/non-validating costumers.