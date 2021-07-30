import os
import sys
import re
import posixpath
import argparse
from pathlib import Path
from shutil import copyfile

name_reg = re.compile(r"(/[0-9][0-9]\.)+")


def filter_string(string, string_replace='/', regex=name_reg):
    return re.sub(regex, string_replace, string)


# Input: dirname_from: where you want to migrate from. migrate_rootpath: path including the new root dir of the structure
def transform_wiki(dirname_from, migrate_rootpath):

    # New file structure
    Path(migrate_rootpath).mkdir(parents=True, exist_ok=True)
    dir_path_new = None

    for root, dirs, files in os.walk('./' + dirname_from, topdown=False):

        # Filter the new names i dst
        root_src = root
        root_dst = filter_string(root, '/', name_reg)
       
        # Make a new regural dirs (without bottom dir which is replaced by .md file)
        path = '/'.join(root_dst.split('/')[2:-1])   # The path following the root dir (./Pages)
        dir_path_new = migrate_rootpath + '/' + path
        Path(dir_path_new).mkdir(parents=True, exist_ok=True)

        for file_name in files:
            
            # File path in original structure
            file_path_scr = root_src + "/" + file_name

            # Test for only altering .md-files
            if not file_name.endswith(".md"):
                # Copy other files from scr
                src = file_path_scr
                dst = '/'.join([dir_path_new, file_name])
                copyfile(src, dst)
                continue

            # Open original file
            with open(file_path_scr) as f_from:

                try:
                    # New name convention for .md-files migrated to new structure
                    new_filepath = dir_path_new + '/' + os.path.basename(root_dst) + '.md'
                    with open(new_filepath, 'w') as f_to:
                        for line in f_from:
                            f_to.write(line)
          
                except UnicodeDecodeError:
                    print("UnocodeError in :" + file_path_scr)
            

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("dirname", type=str)
    parser.add_argument("migrate_root",type=str)
    args = parser.parse_args()
    transform_wiki(args.dirname, args.migrate_root)
    
