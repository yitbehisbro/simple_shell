# 0x16. C - Simple Shell
<h3>Compilation</h3>

<p>The shell should be compiled this way:</p>

<pre><code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh && ./hsh
</code></pre>
<h3>The shell prompt like:</h3>
<pre><code>:)</code></pre>
<h3>Testing</h3>

<p>The shell works like this in interactive mode:</p>

<pre><code>
:) ./hsh
:) /bin/ls
hsh main.c shell.c
(:))
(:)) exit
:)
</code></pre>

<p>Also in non-interactive mode:</p>

<pre><code>:) echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
:)
:) cat test_ls_2
/bin/ls
/bin/ls
:)
:) cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
:)
</code></pre>
<h3><code>PATH</code> Handling</h3>
<pre><code>yitbe@ubuntu:~/simple_shell$ ./hsh
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell_0.3  stat    test_scripting.sh  wait.c
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     shell.c    stat.c  wait
:) ls -l /tmp 
total 20
-rw------- 1 julien julien    0 Dec  5 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Dec  5 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Dec  5 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 julien julien    0 Dec  5 12:09 unity_support_test.0
:) ^C
yitbe@ubuntu:~/simple_shell$ 
</code></pre>
<h3> <code>env</code></h3>
<pre><code>yitbe@ubuntu:~/simple_shell$ ./hsh
:) env
USER=yitbe
LANGUAGE=en_US
SESSION=ubuntu
COMPIZ_CONFIG_PROFILE=ubuntu
SHLVL=1
HOME=/home/yitbe
C_IS=Fun_:)
DESKTOP_SESSION=ubuntu
LOGNAME=yitbe
TERM=xterm-256color
PATH=/home/yitbe/bin:/home/yitbe/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
DISPLAY=:0
:) exit
yitbe@ubuntu:~/simple_shell$ 
</code></pre>
<h3><code>exit EXIT_STATUS</code></h3>
<pre><code>yitbe@ubuntu:~/simple_shell$ ./hsh
:) exit 14
yitbe@ubuntu:~/simple_shell$ echo $?
14
yitbe@ubuntu:~/simple_shell$ 
</code></pre>
<h3><code>cd</code></h3>
<pre><code>yitbe@ubuntu:~/simple_shell$ ./hsh
:) cd -
/yitbe
:) cd -
/yitbe/simple_shell
:) cd
:) pwd
/yitbe
:) exit
yitbe@ubuntu:~/simple_shell$
</code></pre>
<h3><code>;</code> Separator</h3>
<pre><code>:) ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /hbtn ; ls /var
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /var ; ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
:) ls /var ; ls /hbtn ; ls /var ; ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:)
</code></pre>
<h3><code>&&</code> and <code>||</code></h3>
<pre><code>:) ls /var &amp;&amp; ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /hbtn &amp;&amp; ls /var
ls: cannot access /hbtn: No such file or directory
:) ls /var &amp;&amp; ls /var &amp;&amp; ls /var &amp;&amp; ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
:) ls /var &amp;&amp; ls /var &amp;&amp; ls /var &amp;&amp; ls /hbtn &amp;&amp; ls /hbtn
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
ls: cannot access /hbtn: No such file or directory
:)
:) ls /var || ls /var
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /hbtn || ls /hbtn || ls /hbtn || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:) ls /hbtn || ls /hbtn || ls /hbtn || ls /var || ls /var
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
ls: cannot access /hbtn: No such file or directory
backups  cache  crash  lib  local  lock  log  mail  metrics  opt  run  spool  tmp
:)
</code></pre>
<h3><code>#</code> Comment handling</h3>
<pre><code>yitbe@ubuntu:~/simple_shell$ ./hsh
:) echo $$ # ls -la
5114
:) exit
yitbe@ubuntu:~/simple_shell$
</code></pre>
