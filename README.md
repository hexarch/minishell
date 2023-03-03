aeryilma, aozsayar

for compile u must do:

```rm -rf $HOME/.brew && rm -rf $HOME/goinfre/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/goinfre/.brew && echo 'export PATH=$HOME/goinfre/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update```

and add ```-I~/goinfre/.brew/opt/readline/include``` and ```-L ~/goinfre/.brew/opt/readline/lib```
