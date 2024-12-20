>**Warning:** This code is provided for educational purposes for ILISI only. It is not optimized for production use and may contain bugs or memory leaks. Always review and test the code thoroughly before using it in any project.

# How to work with `GTK`:

The easiest way to explain it: try `OOP` in a non-`OOP` language.

First things first, let's talk about the `GTK`. It is simply a `graphical library`. What does this mean? For you, it is a set of graphical widgets that you can work with. Widgets in our context are the things that you work with in your daily life on a computer, such as `buttons`, `text input`, `navigation bars`, etc.

Always imagine your application with `GTK` like your backpack. It contains all your stuff. Some of your stuff can act like a backpack too, so widgets are either containers or contained. The containers can have a single widget in them or multiple widgets. For example, a `window` widget always has one widget in it, while a `fixed` widget can have as many as you like.

The way you should be working in this project should be organized in a way similar to how we work with classes. I am going to give a simple example of how to do it in the code.

# Example: `Checkbox` button

## Attributes (variables)

### Struct `cocher`
The best way to handle the variables is to encapsulate them in a struct:

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
- **gint x**: This is an integer representing the x-coordinate position of the checkbox (position relative to the parent widget).
- **gint y**: This is an integer representing the y-coordinate position of the checkbox (same as gint x).
- **gchar \*gui**: This is a string that holds the background color of the checkbox in HEX format (e.g., "#000000").
- **struct coche \*next**: This is a pointer to the next checkbox in the linked list.

```c
typedef struct {
    cocher *head; 
} CheckboxList;
```

- **cocher \*head**: for the purpose of encapsulating the `checkBox`

### Functions (Methods)

So for the methods, we should have:

- **Initialization function**: Since we are working with pointers, we should allocate memory for each element in our structure and initialize them with NULL too. This way, we make sure that our widget exists in memory.

```c
CheckboxList *init_checkbox_list() {
    /// you know this right ? :
    CheckboxList *list = (CheckboxList *)malloc(sizeof(CheckboxList));
    /// absolutly necessary to check after every memory allocation
    if (list == NULL) return NULL;
    list->head = NULL;
    return list;
}

void init_cocher_elements(cocher *C) {
    /// simple as that
    C->name = NULL;
    C->parent = NULL;
    C->label = NULL;
    C->boutcoche = NULL;
    C->x = 0;
    C->y = 0;
    C->gui = NULL;
    C->next = NULL;
}
```

- **Creation function**: This function is called after the initialization. Our purpose is to assign the values chosen by the user to the widget. The values are the ones mentioned in the structs of the widget.

```c
cocher *create_cocher(GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    cocher *C = (cocher *)malloc(sizeof(cocher));
    if (C == NULL) return NULL;
    init_cocher_elements(C);
    /// now every attributs you had in the struct should be filled with what the user want  
    if(name) C->name = name;
    if(parent) C->parent = parent;
    if(label) C->label = g_strdup(label);
    if(x) C->x = x;
    if(y) C->y = y;
    C->boutcoche = gtk_check_button_new_with_label(C->label);
    C->next = NULL;

    /// colors in gtk are a bit complicated you should personnalise how you do it based on the widget
    if (gui) {
        C->gui = g_strdup(gui);
        GdkColor color;
        gdk_color_parse(C->gui, &color);
        gtk_widget_modify_bg(C->boutcoche, GTK_STATE_NORMAL, &color);
    }
    /// necessary to make sure that any css applied is going to be directly linked to the widget
    if (C->name)
        gtk_widget_set_name(C->boutcoche, C->name);
    /// this is just to make the button checked since the beggining
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(C->boutcoche), checked);

    return C;
}
```

- **Add function**: This function is used upon the creation of the type in the program. It should be the only one of these three already mentioned that we can access in the program.

```c
GtkWidget *add_cocher(CheckboxList *list, GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    /// either call in init function than create function or call the init function inside the create function
    cocher *checkbox = create_cocher(parent, label, x, y, gui, checked, name);
    if (checkbox == NULL) return NULL;

    /// this depends on the widget since we are wokring with a linked list we need to assure it is linked.
    checkbox->next = list->head;
    list->head = checkbox;

    return checkbox->boutcoche;
}
```

- **Other**: Each widget may have or need tweaking to work with. For example, if we are working with the fixed widget (a widget that we can put other widgets in using the x and y position), you need to add a function that you give the widget you want to add to in the parameters. So, besides the three critical functions already mentioned, feel free to add any ones you judge are necessary for the widget.

# Things we didn't do and we recommend you to do

## Free function

Working with pointers and malloc function without freeing will cause problems. It may not seem a problem at first, but when you build your project and things get big at a certain point, memory leaks become an obstacle. Don't get me wrong, we used free() for the widget we allocated memory with, but it wasn't really the good way to do it. So, a function added to every widget file that contains the appropriate free logic would help you.

## Either CamelCase or snake_case

Camel case is when you name your variable this way: `VariableName`, making sure that the first letter of every word is in uppercase.

Snake case is using _ to separate the words: `variable_name`.

Choose one with your group. It makes looking for variables easier, trust me.

## French or English

Simply choose one language to work with. I recommend English since the resources are in English, but make sure to know how to explain it in French for your reports and when you explain things to your Professor.

## Work with Git/GitHub

To take control of what is happening in your project, don't send your code in a text message in your WhatsApp group, please. Linus will be disappointed.

# Conclusion

Don't take this code because it is not made properly, and trust me when I say that `THE` Professor will know that you copied it. He may even know that you copied it from mine, but you need to do something similar to what I explained in this readme file.**Warning:** This code is provided for educational purposes for ILISI only. It is not optimized for production use and may contain bugs or memory leaks. Always review and test the code thoroughly before using it in any project.

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
- **gint x**: This is an integer representing the x-coordinate position of the checkbox (positon relative to the parent widget).
- **gint y**: This is an integer representing the y-coordinate position of the checkbox (samr as gint x).
- **gchar \*gui**: This is a string that holds the background color of the checkbox in HEX format (e.g., "#000000").
- **struct coche \*next**: This is a pointer to the next checkbox in the linked list.


```c
typedef struct {
    cocher *head; 
} CheckboxList;
```

- **cocher \*head**: for the purpose of encapsulating the `checkBox`

### Functions (Methods)

So for the methods, we should have : 

-**Initialisation function** :  since we are working with pointers, we should allow memory for each element in our structure, initialiase them with NULL too, this way we make sure that our widget exist in memory,

```c
CheckboxList *init_checkbox_list() {
    /// you know this right ? :
    CheckboxList *list = (CheckboxList *)malloc(sizeof(CheckboxList));
    /// absolutly necessary to check after every memory allocation
    if (list == NULL) return NULL;
    list->head = NULL;
    return list;
}

void init_cocher_elements(cocher *C) {
    /// simple as that
    C->name = NULL;
    C->parent = NULL;
    C->label = NULL;
    C->boutcoche = NULL;
    C->x = 0;
    C->y = 0;
    C->gui = NULL;
    C->next = NULL;
}
```

-**Creation function** : this function is called after the initialisation, our purpose is to affest the values chosen by the user to the widget,the values are the ones mentionned in the structs of the widget.

```c
cocher *create_cocher(GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    cocher *C = (cocher *)malloc(sizeof(cocher));
    if (C == NULL) return NULL;
    init_cocher_elements(C);
    /// now every attributs you had in the struct should be filled with what the user want  
    if(name) C->name = name;
    if(parent) C->parent = parent;
    if(label) C->label = g_strdup(label);
    if(x) C->x = x;
    if(y) C->y = y;
    C->boutcoche = gtk_check_button_new_with_label(C->label);
    C->next = NULL;

    /// colors in gtk are but complicated you should personnalise how you do it based on the widget
    if (gui) {
        C->gui = g_strdup(gui);
        GdkColor color;
        gdk_color_parse(C->gui, &color);
        gtk_widget_modify_bg(C->boutcoche, GTK_STATE_NORMAL, &color);
    }
    /// necessary to make sure that any css applied is going to be directly linked to the widget
    if (C->name)
        gtk_widget_set_name(C->boutcoche, C->name);
    /// this is just to make the button checked since the beggining
    gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(C->boutcoche), checked);

    return C;
}
```


-**Add function** : this function is used upon the creation of the type in the program, it should be the only one of these three already mentionned that we can access in the program.

```c
GtkWidget *add_cocher(CheckboxList *list, GtkWidget *parent, gchar *label, gint x, gint y, gchar *gui, gboolean checked, gchar* name) {
    /// either call in init function than create function or call the init function inside the create function
    cocher *checkbox = create_cocher(parent, label, x, y, gui, checked, name);
    if (checkbox == NULL) return NULL;

    /// this depends on the widget since we are wokring with a linked list we need to assure it is linked.
    checkbox->next = list->head;
    list->head = checkbox;

    return checkbox->boutcoche;
}
```

-**Other** : each widget may have or need a tweaking to work with, for example if we are working with the fixed widget (a widget that we can put other widget in using the x and y position), you need to add a function that you give the widget you want to add too in the parameters, so beside the three critical function already mentionned, feel free to add any ones you judge are necessary for the widget.

# Thing we didn't do and we recomend you to do it

## Free function

working with pointers and malloc function without freeing will cause problems, it may not seem a problem first but when you will be building you project and things get big at a certain point and memory leaks become an obstacle, don't get me wrong we used free() for the widget we allocated memory with, but it wasn't really the good way to do it, so a function added to every widget file that contain the appropriate free logic would help you.

## Either CamelCase or snake_case

camel case is when you name you variable this way : `VariableName` making sure that the first letter of every word is in uppercase.

snake case is using _ to separate the words : `variable_name`.

choose one with you group, it makes looking for variable eisier trust me.

## French or English

Simply choose one langage to work with, i recomend english since the ressources are in english but make sure to know how to explain it in french for your reports and when you explain things to your Professor.

## Work with Git/Github

To take control of what is happening in your project, don't send your code in a text message in your whatsapp group please, Linus will be dissapointed.

># Warning
>Don't take this code because it is not made properly and trust me when i say that `THE` Professor will know that you copied it, he may even know that you copied it from mine, you need to do something similar to what i explained in this readme file.


# ressources

Installation process for gtk in codeblocks : 

https://www.youtube.com/watch?v=zoH9jIj3Ldo&t=992s

Gtk official documentation : 

https://www.gtk.org/docs/

Gtk non-official but good enough documentation : 

https://devdocs.io/gtk~3.20/gtkbuttonbox



