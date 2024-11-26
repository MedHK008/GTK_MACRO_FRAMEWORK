# How to work with `GTK` : 

The easiest way to explain it : try `OOP` in a non `OOP` langage.

First things first let's talk about the `GTK`, it is simply a `graphical library`, what does this mean ? For you it is a set of graphical widget that you can work with, widget in our context are the thing that you work with in you daily life on computer, `buttons`,`text input`, `navigation bars`.... 

Always imagine your application with `GTK` like you backpack, it contains all your stuff, some of your stuff can act like a backpack too, so widget are either containers or contained, the containers can have a single widget in them or multiple widgets, for example, a `window` widget always have one widget in it, a `fixed` widget can have as many as you like

The way you should be working in this project, should be organized in a way simalar to how we work with classes, i am going to give a simple example of how to do it in the code.

# Example : `Checkbox` button

## Attributes (variables)

### Struct `cocher`
The best way to handle the variables is to encapsulate them in a struct : 

```c
typedef struct coche {
    GtkWidget *parent;
    gchar *label;
    gchar *name;
    GtkWidget *boutcoche;
    gint x;
    gint y;
    gchar *gui;
    struct coche *next;
} cocher;
```

- **GtkWidget \*parent**: This is a pointer to the parent widget that contains the checkbox.
- **gchar \*label**: This is a string that holds the label text for the checkbox.
- **gchar \*name**: This is a string that holds the name (ID) of the checkbox, which can be used for styling with CSS.
- **GtkWidget \*boutcoche**: This is a pointer to the actual GTK checkbox widget.
- **gint x**: This is an integer representing the x-coordinate position of the checkbox.
- **gint y**: This is an integer representing the y-coordinate position of the checkbox.
- **gchar \*gui**: This is a string that holds the background color of the checkbox in HEX format (e.g., "#000000").
- **struct coche \*next**: This is a pointer to the next checkbox in the linked list.
