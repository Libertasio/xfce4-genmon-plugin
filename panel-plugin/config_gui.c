/*
 *  Generic Monitor plugin for the Xfce4 panel
 *  Copyright (c) 2004 Roger Seguin <roger_seguin@msn.com>
 *  					<http://rmlx.dyndns.org>
 *  
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.

 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.

 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

static char     RCSid[] =
    "$Id: config_gui.c,v 1.1.1.2 2004/11/01 00:22:46 rogerms Exp $";


#include "config_gui.h"

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include <libxfce4util/i18n.h>
#include <libxfcegui4/dialogs.h>
#include <panel/plugins.h>
#include <panel/xfce.h>


#define COPYVAL(var, field)	((var)->field = field)


	/**** GUI initially created using glade-2 ****/

	/* Use the gtk_button_new_with_mnemonic() function for text-based
	   push buttons */
	/* Use "#define gtk_button_new_with_mnemonic(x) gtk_button_new()"
	   for color-filled buttons */

#define gtk_button_new_with_mnemonic(x) gtk_button_new()

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

#if 0
GtkWidget      *create_OptionDialog (void)
#else
int genmon_CreateConfigGUI (GtkWidget * OptionDialog,
			    struct gui_t *p_poGUI)
#endif
{
#if 0
    GtkWidget      *OptionDialog;
#endif
    GtkWidget      *vbox1;
    GtkWidget      *wPB_About;
    GtkWidget      *alignment2;
    GtkWidget      *hbox3;
    GtkWidget      *image1;
    GtkWidget      *label10;
    GtkWidget      *hseparator9;
    GtkWidget      *table1;
    GtkWidget      *label1;
    GtkWidget      *wTF_Cmd;
    GtkWidget      *eventbox1;
    GtkWidget      *alignment1;
    GtkObject      *wSc_Period_adj;
    GtkWidget      *wSc_Period;
    GtkWidget      *label2;
    GtkWidget      *wTB_Title;
    GtkWidget      *wTF_Title;
    GtkWidget      *hseparator10;
    GtkWidget      *wPB_Font;
    GtkWidget      *alignment3;
    GtkWidget      *hbox4;
    GtkWidget      *image2;
    GtkWidget      *label11;
    GtkTooltips    *tooltips;

    tooltips = gtk_tooltips_new ();

#if 0
    OptionDialog = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (OptionDialog), _("OptionDialog"));
#endif

    vbox1 = gtk_vbox_new (FALSE, 0);
    gtk_widget_show (vbox1);
    gtk_container_add (GTK_CONTAINER (OptionDialog), vbox1);

    wPB_About = gtk_button_new ();
    gtk_widget_show (wPB_About);
    gtk_box_pack_start (GTK_BOX (vbox1), wPB_About, FALSE, FALSE, 0);
    GTK_WIDGET_UNSET_FLAGS (wPB_About, GTK_CAN_FOCUS);
    gtk_tooltips_set_tip (tooltips, wPB_About, _("About..."), NULL);
    gtk_button_set_relief (GTK_BUTTON (wPB_About), GTK_RELIEF_NONE);

    alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
    gtk_widget_show (alignment2);
    gtk_container_add (GTK_CONTAINER (wPB_About), alignment2);

    hbox3 = gtk_hbox_new (FALSE, 2);
    gtk_widget_show (hbox3);
    gtk_container_add (GTK_CONTAINER (alignment2), hbox3);

    image1 =
	gtk_image_new_from_stock ("gnome-stock-about",
				  GTK_ICON_SIZE_BUTTON);
    gtk_widget_show (image1);
    gtk_box_pack_start (GTK_BOX (hbox3), image1, FALSE, FALSE, 0);

    label10 = gtk_label_new_with_mnemonic (_("Generic Monitor"));
    gtk_widget_show (label10);
    gtk_box_pack_start (GTK_BOX (hbox3), label10, FALSE, FALSE, 0);
    gtk_label_set_justify (GTK_LABEL (label10), GTK_JUSTIFY_LEFT);

    hseparator9 = gtk_hseparator_new ();
    gtk_widget_show (hseparator9);
    gtk_box_pack_start (GTK_BOX (vbox1), hseparator9, TRUE, TRUE, 0);

    table1 = gtk_table_new (3, 2, FALSE);
    gtk_widget_show (table1);
    gtk_box_pack_start (GTK_BOX (vbox1), table1, FALSE, TRUE, 0);

    label1 = gtk_label_new (_("Command"));
    gtk_widget_show (label1);
    gtk_table_attach (GTK_TABLE (table1), label1, 0, 1, 0, 1,
		      (GtkAttachOptions) (GTK_FILL),
		      (GtkAttachOptions) (0), 0, 0);
    gtk_label_set_justify (GTK_LABEL (label1), GTK_JUSTIFY_LEFT);
    gtk_misc_set_alignment (GTK_MISC (label1), 0, 0.5);

    wTF_Cmd = gtk_entry_new ();
    gtk_widget_show (wTF_Cmd);
    gtk_table_attach (GTK_TABLE (table1), wTF_Cmd, 1, 2, 0, 1,
		      (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
		      (GtkAttachOptions) (0), 0, 0);
    gtk_tooltips_set_tip (tooltips, wTF_Cmd,
			  _
			  ("Input the shell command to spawn, then press <Enter>"),
			  NULL);
    gtk_entry_set_max_length (GTK_ENTRY (wTF_Cmd), 128);

    eventbox1 = gtk_event_box_new ();
    gtk_widget_show (eventbox1);
    gtk_table_attach (GTK_TABLE (table1), eventbox1, 1, 2, 2, 3,
		      (GtkAttachOptions) (GTK_FILL),
		      (GtkAttachOptions) (GTK_FILL), 0, 0);

    alignment1 = gtk_alignment_new (0.5, 0.5, 1, 1);
    gtk_widget_show (alignment1);
    gtk_container_add (GTK_CONTAINER (eventbox1), alignment1);

    wSc_Period_adj = gtk_adjustment_new (15, 1, 3600, 1, 1, 10);
    wSc_Period =
	gtk_spin_button_new (GTK_ADJUSTMENT (wSc_Period_adj), 1, 0);
    gtk_widget_show (wSc_Period);
    gtk_container_add (GTK_CONTAINER (alignment1), wSc_Period);
    gtk_tooltips_set_tip (tooltips, wSc_Period,
			  _("Interval between 2 consecutive spawns"),
			  NULL);
    gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (wSc_Period), TRUE);

    label2 = gtk_label_new (_("Period (s) "));
    gtk_widget_show (label2);
    gtk_table_attach (GTK_TABLE (table1), label2, 0, 1, 2, 3,
		      (GtkAttachOptions) (GTK_FILL),
		      (GtkAttachOptions) (0), 0, 0);
    gtk_label_set_justify (GTK_LABEL (label2), GTK_JUSTIFY_LEFT);
    gtk_misc_set_alignment (GTK_MISC (label2), 0, 0.5);

    wTB_Title = gtk_check_button_new_with_mnemonic (_("Label"));
    gtk_widget_show (wTB_Title);
    gtk_table_attach (GTK_TABLE (table1), wTB_Title, 0, 1, 1, 2,
		      (GtkAttachOptions) (GTK_FILL),
		      (GtkAttachOptions) (0), 0, 0);
    gtk_tooltips_set_tip (tooltips, wTB_Title, _("Tick to display label"),
			  NULL);

    wTF_Title = gtk_entry_new ();
    gtk_widget_show (wTF_Title);
    gtk_table_attach (GTK_TABLE (table1), wTF_Title, 1, 2, 1, 2,
		      (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
		      (GtkAttachOptions) (0), 0, 0);
    gtk_tooltips_set_tip (tooltips, wTF_Title,
			  _("Input the plugin label, then press <Enter>"),
			  NULL);
    gtk_entry_set_max_length (GTK_ENTRY (wTF_Title), 16);
    gtk_entry_set_text (GTK_ENTRY (wTF_Title), _("(genmon)"));

    hseparator10 = gtk_hseparator_new ();
    gtk_widget_show (hseparator10);
    gtk_box_pack_start (GTK_BOX (vbox1), hseparator10, FALSE, FALSE, 0);

    wPB_Font = gtk_button_new ();
    gtk_widget_show (wPB_Font);
    gtk_box_pack_start (GTK_BOX (vbox1), wPB_Font, FALSE, FALSE, 0);
    gtk_tooltips_set_tip (tooltips, wPB_Font, _("Press to change font"),
			  NULL);

    alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
    gtk_widget_show (alignment3);
    gtk_container_add (GTK_CONTAINER (wPB_Font), alignment3);

    hbox4 = gtk_hbox_new (FALSE, 2);
    gtk_widget_show (hbox4);
    gtk_container_add (GTK_CONTAINER (alignment3), hbox4);

    image2 =
	gtk_image_new_from_stock ("gtk-select-font", GTK_ICON_SIZE_BUTTON);
    gtk_widget_show (image2);
    gtk_box_pack_start (GTK_BOX (hbox4), image2, FALSE, FALSE, 0);

    label11 = gtk_label_new_with_mnemonic (_("(Default font)"));
    gtk_widget_show (label11);
    gtk_box_pack_start (GTK_BOX (hbox4), label11, FALSE, FALSE, 0);
    gtk_label_set_justify (GTK_LABEL (label11), GTK_JUSTIFY_LEFT);

    if (p_poGUI) {
	COPYVAL (p_poGUI, wPB_About);
	COPYVAL (p_poGUI, wTF_Cmd);
	COPYVAL (p_poGUI, wTB_Title);
	COPYVAL (p_poGUI, wTF_Title);
	COPYVAL (p_poGUI, wSc_Period);
	COPYVAL (p_poGUI, wPB_Font);
    }
    return (0);
}				/* CreateConfigGUI() */


/*
$Log: config_gui.c,v $
Revision 1.1.1.2  2004/11/01 00:22:46  rogerms
*** empty log message ***

Revision 1.1.1.1  2004/09/09 13:35:51  rogerms
V1.0

Revision 1.2  2004/08/28 09:53:28  RogerSeguin
Added font selector

Revision 1.1  2004/08/27 23:17:29  RogerSeguin
Initial revision

*/
