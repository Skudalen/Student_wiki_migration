import os
import subprocess

for root,dirs, files in os.walk("./2018"):
    print(root,dirs,files)
    for file_name in files:
        if file_name.endswith("index.md"):
            print(file_name)
            subprocess.run(["echo",file_name],cwd=root)
            subprocess.run(["asciidoctor","-b", "docbook", file_name,"-o","index.xml"],cwd=root)
            subprocess.run(["pandoc","-f","docbook","-t", "gfm", "index.xml", "-o", "README.md"],cwd=root)
            subprocess.run(["rm","index.xml","index.md"],cwd=root)
