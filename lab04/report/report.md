---
# Front matter
title: "Информационная безопасность."
subtitle: "Лабораторная работа №4."
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

Получение практических навыков работы в консоли с расширенными атрибутами файлов

# Задание

1) Выполнить пункты из задания по порядку.


# Выполнение лабораторной работы

От имени пользователя `guest` определил расширенные атрибуты файла `/home/guest/dir1/file1` командой `lsattr /home/guest/dir1/file1`

![Определение расширенных атрибутов](../images/1.png){ #fig:001 width=70% }

Установил командой `chmod 600 file1` на файл `file1` права, разрешающие чтение и запись для владельца файла.

![Установление на файл прав разрешающих чтение и запись.](../images/2.png){ #fig:002 width=70% }

Попробовал установить на файл `/home/guest/dir1/file1` расширенный атрибут a от имени пользователя guest: `chattr +a /home/guest/dir1/file1`, но получил отказ

![Добавление расширенного атрибута a](../images/3.png){ #fig:003 width=70% }

От имени администратора установил на файл расширенный атрибут a. `chattr +a /home/guest/dir1/file1`

![Установление расширенного атрибута а от sudo](../images/4.png){ #fig:004 width=70% }

От пользователя guest проверил правильность установления атрибута: `lsattr /home/guest/dir1/file1`

![Проверка установки расширенного атрибута a](../images/5.png){ #fig:005 width=70% }

Выполнил дозапись в файл file1 слова "test" командой `echo "test /home/guest/dir1/file1"`.

![Дозапись в файл](../images/6.png){ #fig:006 width=70% }

После этого выполнил чтение файла командой `cat /home/guest/dir1/file1`

![Чтение файла](../images/7.png){ #fig:007 width=70% }

Попробовал удалить файл, либо стереть имеющуюся в нём информацию командой `echo`.
Попробовал переименовать файл. Попробовал также изменить атрибуты файла командой
`chmod`. Все перечисленные операции не были позволены.

![Действия над файлом](../images/8.png){ #fig:008 width=70% }

Снял расширенный атрибут а с файла командой `chattr -a /home/guest/dir1/file1`

![Снятие расширенного атрибута а](../images/9.png){ #fig:009 width=70% }

Попробовал выполнить все вышеперечисленные команды. На этот раз операции были позволены.

![Действия над файлом.](../images/10.png){ #fig:010 width=70% }

Установил на файл расширенный атрибут i.

![Установление расширенного атрибута i](../images/12.png){ #fig:012 width=70% }

Попробовал повторить все вышеперечисленные операции. Команды не были позволены.

![Действия над файлом.](../images/13.png){ #fig:013 width=70% }

# Выводы

Получил практические навыки работы в консоли с расширенными атрибутами файлов
