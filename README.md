# nmscrub
"Name Scrub" Removes a given string from the filenames in a list of file paths. Shouldn't break when it hits a filename that does not contain the string. It should just throw a warning and move on.

Usage: "nmscrub string list.txt"

string is what you remove. list is the list of files to rename.
use https://github.com/KaptainBflakes/extlist if you don't want or know how to make lists on your own.
Format the text file with the file paths terminated by newline chars '\n'.
