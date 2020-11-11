# WorkSetup
1. Prerequisite Installations
    1. [vs code](https://code.visualstudio.com/Download)
    2. GIT Linux Package 
        $ sudo apt install git-all
2. Login to Github account and grant the permissions
3. vs code extensions
    1. Git History
    2. Git Pull and Push Request
    3. pdf Viewer
    4. Markdown enhanced viewer
4. git inspector
    1. sudo apt-get install npm
    2. sudo npm i -g gitinspector
    3. sudo apt-get install python
    3. gitinspector -HlmTwr --grading --format=html > gitinsp.html
    
## Actions
    git actions are set in the ".github/workflows" folder in the repository
* [Unit Test by Cmake](.github/workflows/unitTest_Cmake.yml)
* [Unit Testing by Make file](.github/workflows/unit-test.yml)
    * [makefile example](../Linux/DevelopmentTools/5_make-tuto/Notes.md#Example%202)
* [Build](.github/workflows/build.yml)
* [Cpp Check](.github/workflows/cppcheck.yml)
* [Valgrind](.github/workflows/valgrind.yml)

## Reference Links
* [Git Start Docs](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control#ch01-getting-started)
* [Git Actions](https://docs.github.com/en/free-pro-team@latest/actions)
* https://www.codeproject.com/Articles/1214409/Learn-YAML-in-five-minutes

### VSCode
* [Version Control](https://code.visualstudio.com/docs/editor/versioncontrol)
* [Working with Github](https://code.visualstudio.com/docs/editor/github)
* [vs code extension](https://marketplace.visualstudio.com/items?itemName=GitHub.vscode-pull-request-github)

### Markdown(.md)
* [Sample .md file](markdown)
* [How to write readme file?](https://medium.com/@saumya.ranjan/how-to-write-a-readme-md-file-markdown-file-20cb7cbcd6f)
* [Markdown Docs](https://guides.github.com/features/mastering-markdown/)
* [Markdown Writing](https://docs.github.com/en/free-pro-team@latest/github/writing-on-github/basic-writing-and-formatting-syntax)