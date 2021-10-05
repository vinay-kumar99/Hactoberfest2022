# Hactoberfest 2021
Some Basic Program in Various Languages.


#### Update your Repository with main

Add the remote, call it "upstream" :

``` git remote add upstream https://github.com/vinayskywalker/Hactoberfest2020  ```

 Fetch all the branches of that remote into remote-tracking branches,
 such as upstream/main:

``` git fetch upstream ```

Make sure that you're on your main branch:

``` git checkout main ```

Rewrite your main branch so that any commits of yours that
aren't already in upstream/main are replayed on top of that
other branch:

``` git rebase upstream/main ```


