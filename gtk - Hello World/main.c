#include <stdio.h>
#include <gtk/gtk.h>

// Here we want to display a Hello World button
static void
print_hello (GtkWidget *widget, gpointer data){
    // The button function goes here
    g_print ("Button got pressed\n");
}

// Here we want to construct the window to be shown
static void
activate (GtkApplication* app, gpointer user_data){
    // A GtkWidget is declared to accomplish each feature
    GtkWidget *window;
    GtkWidget *button;
    
    window = gtk_application_window_new (app);
    // Define some of the window attributes
    gtk_window_set_title (GTK_WINDOW (window), "Learning GTK 4.0");
    gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
    
    // Returns a GtkButton which is stored in 'button' variable
    button = gtk_button_new_with_label ("I'm a button");
    // Add the button to the widget
    // Connect the button to a CALLBACK function "print_hello" which has any DATA input, so we got a NULL value
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    
    gtk_window_set_child (GTK_WINDOW (window), button);
    
    // Shows the window
    gtk_widget_show (window);
}

// Create the Gtk Application object and run it
int main (int argc, char **argv){


    GtkApplication *app;
    int status;

    // The "gtk_application_new" initialize the "GtkApplication" instance
    // Rules for naming your instance:
    // https://developer.gnome.org/documentation/tutorials/application-id.html
    // The GApplicationFlags define some of the capabilities that your application has
    app = gtk_application_new ("learning.gtk.four", G_APPLICATION_DEFAULT_FLAGS);
    // Sends a signal to "activate"
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);   
    g_object_unref (app);

    return status;
}

// Compiling code
// gcc $( pkg-config --cflags gtk4 ) -o main main.c $( pkg-config --libs gtk4 )