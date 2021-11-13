---
# Front matter
title: "Информационная безопасность."
subtitle: "Лабораторная работа №5."
author: "Подмогильный Иван Александрович."

# Generic otions
lang: ru-RU
toc-title: "Содержание"

# Bibliography

# Pdf output format
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
lot: true # List of tables
fontsize: 12pt
linestretch: 1.5
papersize: a4
documentclass: scrreprt
## I18n
polyglossia-lang:
  name: russian
  options:
  - spelling=modern
  - babelshorthands=true
polyglossia-otherlangs:
  name: english
### Fonts
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase,Scale=0.9
## Biblatex
biblatex: true
biblio-style: "gost-numeric"
biblatexoptions:
  - parentracker=true
  - backend=biber
  - hyperref=auto
  - language=auto
  - autolang=other*
  - citestyle=gost-numeric
## Misc options
indent: true
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Изучение механизмов изменения идентификаторов, применения
SetUID- и Sticky-битов. Получение практических навыков работы в консоли с дополнительными атрибутами. Рассмотрение работы механизма
смены идентификатора процессов пользователей, а также влияние бита
Sticky на запись и удаление файлов

# Задание

1) Выполнить пункты из задания по порядку.

# Выполнение лабораторной работы

Установил gcc с помощью команды `yum install gcc`

![Установка gcc](../images/1.png){ #fig:001 width=70% }

Отменил на текущую сессию SELinux командой `setenforce 0`

![Отключение SELinux](../images/2.png){ #fig:002 width=70% }

Вошёл в систему от имени пользователя guest, создал программу `simpleid.c`

![Создание файла и программы `simpleid.c`](../images/3.png){ #fig:003 width=70% }

Скомпилировал программу и убедился, что файл программы создан: `gcc simpleid.c -o simpleid`

![Комплирование файла](../images/4.png){ #fig:004 width=70% }

Выполнил программу simpleid: `./simpleid`

![Выполнение программы `simpleid`](../images/5.png){ #fig:005 width=70% }

Выполнил программу `id` и сравнил полученный результат с данными предыдущего пункта задания. Полученные значения id совпадают

![Выполнение программы id](../images/6.png){ #fig:006 width=70% }

Усложнил программу, добавив вывод действительных идентификаторов, получившуюися программу назвал `simpleid2.c`

![Усложнение программы](../images/7.png){ #fig:007 width=70% }

Скомпилировал и запустил simpleid2.c `gcc simpleid2.c -o simpleid2`, а затем `./simpleid2`

![Компиляция и запуск](../images/8.png){ #fig:008 width=70% }

От имени суперпользователя выполнил команды: `chown root:guest /home/guest/simpleid2`, а затем `chmod u+s /home/guest/simpleid2`. Первая команда изменяет права на файл с guest на root. А затем устанавливает атрибут SetUID, который запускает программу не с правами пользователя, а с правами владельца файла.
Затем выполнил  проверку изменений с помощью команды `ls -l simpleid2`

![Добавление SetUID](../images/9.png){ #fig:009 width=70% }

Запустил simpleid2 и id: `./simpleid2`, `id`. При данном запуску выводы совпадают.

![Действия над файлом.](../images/10.png){ #fig:010 width=70% }

Проделал то же самое с атрибутом SetGID (установление прав для владеющей группы).

![Установка SetGID](../images/11.png){ #fig:011 width=70% }

Запустил файл. Теперь выводы для группы различны.

![Запуск программы с установленным SetGID](../images/12.png){ #fig:012 width=70% }

Создал программу `readfile.c`

![Создание программы readfile.c](../images/13.png){ #fig:013 width=70% }

Откомпилировал программу: `gcc readfile.c -o readfile`

![Компиляция программы](../images/14.png){ #fig:014 width=70% }

Сменил владельца у файла readfile.c и изменил права так, чтобы только суперпользователь(root) мог прочитать его, a guest не мог.

![Смена владельца у файла readfile.c](../images/15.png){ #fig:015 width=70% }

Проверил, что пользователь guest не может прочитать файл readfile.с

![Проверка](../images/16.png){ #fig:016 width=70% }

Сменил у программы readfile владельца и установил SetU’D-бит.

![Установил SetU'D бит](../images/17.png){ #fig:017 width=70% }

Проверил, может ли программа readfile прочитать файл readfile.c. Может.

![Проверка](../images/16.png){ #fig:018 width=70% }

Проверил, может ли программа readfile прочитать файл /etc/shadow. Может

![Проверка](../images/17.png){ #fig:019 width=70% }

Исследование Sticky-бита. Узнал, установлен ли атрибут Sticky на директории /tmp, для чего выполнил команду `ls -l / | grep tmp`

![Sticky бит на папке tmp](../images/18.png){ #fig:020 width=70% }

От имени пользователя guest создал файл file01.txt в директории /tmp
со словом test `echo "test" > /tmp/file01.txt`

![Создание файла](../images/19.png){ #fig:021 width=70% }

Просмотрел атрибуты у только что созданного файла и разрешил чтение и запись для категории пользователей «все остальные»: `ls -l /tmp/file01.txt`, `chmod o+rw /tmp/file01.txt`, `ls -l /tmp/file01.txt`

![Просмотр атрибутов](../images/20.png){ #fig:022 width=70% }

От пользователя guest2 (не являющегося владельцем) попробовал прочитать файл /tmp/file01.txt: `cat /tmp/file01.txt`

![Чтение файла](../images/21.png){ #fig:023 width=70% }

От пользователя guest2 попробовал записать в файл `/tmp/file01.txt`
слово test3, стерев при этом всю имеющуюся в файле информацию командой
`echo "test3" > /tmp/file01.txt`

Проверил содержимое файла командой `cat /tmp/file01.txt`

От пользователя guest2 попробовал дозаписать в файл `/tmp/file01.txt` слово test2 командой `echo "test2" >> /tmp/file01.txt`

Проверил содержимое файла командой `cat /tmp/file01.txt`

![Запись и дозапись](../images/22.png){ #fig:024 width=70% }

От пользователя guest2 попробовал удалить файл /tmp/file01.txt командой `rm /tmp/file01.txt` Файл удалить не удалось.

![Попытка удалить файл](../images/23.png){ #fig:025 width=70% }

Повысил свои права до суперпользователя следующей командой `su -`
и выполнил после этого команду, снимающую атрибут t (Sticky-бит) с
директории /tmp: `chmod -t /tmp`

![Снятие Sticky атрибута](../images/24.png){ #fig:026 width=70% }

Повысил свои права до суперпользователя и вернул атрибут `t` на директорию /tmp: `su -`, `chmod +t /tmp`, `exit`

![Выход из суперпользователя](../images/25.png){ #fig:027 width=70% }

# Выводы

Изучил механизмы изменения идентификаторов, применения
SetUID- и Sticky-битов. Получил практические навыки работы в консоли с дополнительными атрибутами. Рассмотрел работу механизма
смены идентификатора процессов пользователей, а также влияние бита
Sticky на запись и удаление файлов.
