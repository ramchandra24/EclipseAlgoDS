import webbrowser
import os

profile = "Default"
chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe --profile-directory="{}" %s'.format(profile)
here = os.path.dirname(os.path.abspath(__file__))

filename = os.path.join(here, "filename.txt")

with open(filename, "r") as fil:
    all_lines = fil.readlines()
    for url in all_lines:
        webbrowser.open(url, new=2)