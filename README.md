# Hactoberfest 2022
Some Basic Program in Various Languages.


#### Update your Repository with main

Add the remote, call it "upstream" :

```bash
git remote add upstream https://github.com/vinayskywalker/Hactoberfest2021
```

 Fetch all the branches of that remote into remote-tracking branches,
 such as upstream/main:

```bash
git fetch upstream 
```

Make sure that you're on your main branch:

```bash
git checkout main 
```

Rewrite your main branch so that any commits of yours that
aren't already in upstream/main are replayed on top of that
other branch:

```bash
git rebase upstream/main
```


