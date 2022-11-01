#include <stdio.h>
#include <gtk/gtk.h>

static void
activate (GtkApplication* app, gpointer user_data){
    GtkWidget *window;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Learning GTK 4.0");
    gtk_window_set_default_size (GTK_WINDOW (window), 400, 400);
    gtk_widget_show (window);
}

int main (int argc, char **argv){

    GtkApplication *app;
    int status;

    app = gtk_application_new ("learning.gtk.four", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}

// Compiling code
// gcc $( pkg-config --cflags gtk4 ) -o main main.c $( pkg-config --libs gtk4 )