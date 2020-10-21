# Git Commands

## All Commands
    $ git init                                                 # Create Empty respo
    $ git clone https://github.com/99002623/Genesis.git        # Clone Git repository 
    $ git status                                               # Check the untracked files
    $ git add .                                                # To add all files not staged   
    $ git add index.html                                       # To stage a specific file      
    $ git add css                                              # To stage directory   
    $ git config --global user.email "nagaakhil.es@ltts.com"   # for config email(1)
    $ git config --global user.name "Naga Akhil ES"            # git config name(2)
    $ git commit -m "Commit message in quotes"                 # git commit(Local Update)
    $ git commit --amend -m “message”                          # Change to already commit file
    $ git push                                                 # Remote update
    $ git pull                                                 # Local update
    $ git checkout -b test                                     # To switch to test branch
    $ git merge hotfix                                         # Merge Changes
    $ git branch -d localBranchName
    $ git push origin --delete origin/test
                                                
## StartUp Guide
* git clone
* git config for any push and pull actions
* permission granting to upload the git respo content


## Commands to update Remote Repository by Local Repository
    $ Configure Git Transactions using git config
    $ git status                                 # Checking the status
    $ git add .                                  # Stagging
    $ git commit -m "Git Commands update"        # Update Local Repository
    $ git push                                   # Update Remote Repository
    $ git add . && git commit -m "Git Commands update"      #Commit and update

## Create Branches

## other commads
    $ git --version 
    $ git branches

## Reference Links
http://guides.beanstalkapp.com/version-control/common-git-commands.html



