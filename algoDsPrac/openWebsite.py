import webbrowser
import os

here = os.path.dirname(os.path.abspath(__file__))

filename = os.path.join(here, "filename.txt")

with open(filename, "r") as fil:
    all_lines = fil.readline()
    for url in all_lines:
        webbrowser.open(url, new=2)