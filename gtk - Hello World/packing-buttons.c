#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

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
    GtkWidget *grid;
    
    /* Defines some window attribbutes */
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Packing Buttons");
    gtk_window_set_default_size (GTK_WINDOW (window), 500, 400);
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    /* Create the constructor to pack our buttons */
    grid = gtk_grid_new();

    /* Pack the container to the window */
    gtk_container_add (GTK_CONTAINER (window), grid);

    button = gtk_button_new_with_label ("Say Hello");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    /* Place the first button in the grid cell (0, 0),
    and make it fill just 1 cell horizontally and vertically */
    gtk_grid_attach (GTK_GRID (grid), button, 0, 0, 1, 1);

    button = gtk_button_new_with_label ("Say Hello");
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    gtk_grid_attach (GTK_GRID (grid), button, 1, 0, 1, 1);

    button = gtk_button_new_with_label ("Quit");
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window); //Destroys the window if the button get clicked
    gtk_grid_attach (GTK_GRID (grid), button, 0, 1, 2, 1);
    
    // Shows the windowclear
    gtk_widget_show_all (window);
}

// Create the Gtk Application object and run it
int main (int argc, char **argv){
    
    GtkApplication *app;
    int status;

    /* 
    The "gtk_application_new" initialize the "GtkApplication" instance
    Rules for naming your instance:
    https://developer.gnome.org/documentation/tutorials/application-id.html
    The GApplicationFlags define some of the capabilities that your application has
     */
    app = gtk_application_new ("learning.gtk.four", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);   
    g_object_unref (app);

    return status;
}