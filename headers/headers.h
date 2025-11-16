#pragma once

/// system headers
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// user headers
#include "Label.h"           // Must be included first because it defines 'texte' type
#include "CheckBox.h"
#include "Combobox.h"
#include "Entry.h"
#include "Fixed.h"
#include "Frame.h"           // Depends on 'texte' from Label.h
#include "Image.h"
#include "Menu.h"
#include "MessageBox.h"
#include "ProgressBar.h"
#include "RadioButton.h"
#include "ScrollBar.h"
#include "SimpleButton.h"
#include "SpinButton.h"
#include "Tab.h"
#include "ToolBar.h"
#include "Window.h"

#define GTKLOGO "gtklogo.png"
#define IMAGE IMAGE
#define EXAMPLE EXAMPLE