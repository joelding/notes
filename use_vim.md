#VIM
This document records experiences working on vim.

vim runs very slowly on big files. This plugin [\[link\]](http://www.vim.org/scripts/script.php?script_id=1506) suspends parts of functions to accelerate. 
Download LargeFile.vba.gz and run **vim LargeFile.vba.gz**. In vim, run **:so %** to install. 
in ~/.vimrc, setup a size in megabyte over which will trigger the plugin: **let g:LargeFile=5** (5MB)
