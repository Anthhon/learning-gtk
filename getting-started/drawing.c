#include<gtk/gtk.h>
#include"primebreaker.h"

static void break_prime_value( GtkWidget *widget, gpointer data ){
		break_prime(77);
}

static void activate ( GtkApplication *app, gpointer user_data ){
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *value;
  GtkWidget *grid;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW(window), "Breaking Primes");

  // Set grid
  grid = gtk_grid_new();
  gtk_window_set_child ( GTK_WINDOW (window), grid);

  // Creates a text field
  value = gtk_text_new();

  // Creates a button to start hard coding
  button = gtk_button_new_with_label ("Start");
  g_signal_connect ( button, "clicked", G_CALLBACK(print_hello), NULL );
  gtk_grid_attach ( GTK_GRID (grid), button, 0, 0, 2, 1 );

  // Creates another button to quit 
  button = gtk_button_new_with_label ("Quit");
  g_signal_connect_swapped ( button, "clicked", G_CALLBACK ( gtk_window_destroy ), window);
  gtk_grid_attach ( GTK_GRID (grid), button, 0, 1, 2, 1 );

  gtk_widget_show (window); // Display window 
}

int main ( int argc, char **argv ){
  GtkApplication *app;
  int status;

  app = gtk_application_new ( "org.anthony.helloworld", G_APPLICATION_FLAGS_NONE );
  g_signal_connect ( app, "activate", G_CALLBACK (activate), NULL );
  status = g_application_run ( G_APPLICATION (app), argc, argv );
  g_object_unref (app);

  return status;
}
