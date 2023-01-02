#include <stdio.h>
#include<gtk/gtk.h>

static void activate ( GtkApplication* app, gpointer user_data ){
		GtkWidget *window;

		// Set main window properties as
		window = gtk_application_window_new(app);
		gtk_window_set_title( GTK_WINDOW(window), "Blank screen" ); // Set window name
		gtk_window_set_default_size( GTK_WINDOW(window), 250, 500 ); // Set default screen size
		gtk_widget_show(window);
}

int main( int argc, char **argv ){
		GtkApplication *app;
		int status;

		// "gtk_application_new" sets an id, if you want to know more about it, follow the link
		// https://developer.gnome.org/documentation/tutorials/application-id.html
		app = gtk_application_new( "org.anthony.randomapp", G_APPLICATION_FLAGS_NONE );
		g_signal_connect( app, "activate", G_CALLBACK( activate ), NULL);
		status = g_application_run( G_APPLICATION( app ), argc, argv );
		g_object_unref( app );

		return status;
}
