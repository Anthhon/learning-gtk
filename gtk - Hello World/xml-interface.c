#include<stdio.h>
#include<stdlib.h>
#include<gtk/gtk.h>

static void
print_hello (GtkWidget *widget, gpointer data){
    g_print ("Button got pressed\n");
}

int
main (int argc, char *argv[]) {
    
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *button;
    GError *error = NULL;
    
    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0)
    {
      g_printerr ("Impossible to load file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

    /* Defines some window attribbutes */
    window = gtk_builder_get_object ( builder, "window" );
    g_signal_connect ( window, "destroy", G_CALLBACK ( gtk_main_quit ), NULL );

    button = gtk_builder_get_object ( builder, "button1" );
    g_signal_connect ( button, "clicked", G_CALLBACK ( print_hello ), NULL);
    
    button = gtk_builder_get_object ( builder, "button2" );
    g_signal_connect ( button, "clicked", G_CALLBACK ( print_hello ), NULL);

    button = gtk_builder_get_object ( builder, "quit" );
    g_signal_connect ( button, "clicked", G_CALLBACK ( gtk_main_quit ), NULL);

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