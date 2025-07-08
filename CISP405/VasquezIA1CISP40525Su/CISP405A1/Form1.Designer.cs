// Name: Israel Vasquez
// Assignment#: A1
// File Name: Form1.Designer.cs
// Purpose: Store the code for the From1 Designer, all the properties added/created will be located in this file.
// Course: CISP 405 SU25

namespace CISP405A1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Calendar = new Label();
            Appointments = new Label();
            monthCalendar1 = new MonthCalendar();
            richTextBox1 = new RichTextBox();
            Myname = new TextBox();
            SuspendLayout();
            // 
            // Calendar
            // 
            Calendar.Anchor = AnchorStyles.None;
            Calendar.BackColor = Color.Yellow;
            Calendar.Font = new Font("Segoe UI", 12F);
            Calendar.ImageAlign = ContentAlignment.MiddleLeft;
            Calendar.Location = new Point(69, 26);
            Calendar.Name = "Calendar";
            Calendar.Size = new Size(178, 21);
            Calendar.TabIndex = 0;
            Calendar.Text = "Calendar";
            Calendar.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // Appointments
            // 
            Appointments.Anchor = AnchorStyles.None;
            Appointments.BackColor = Color.Yellow;
            Appointments.Font = new Font("Segoe UI", 12F);
            Appointments.Location = new Point(69, 227);
            Appointments.Name = "Appointments";
            Appointments.Size = new Size(178, 21);
            Appointments.TabIndex = 1;
            Appointments.Text = "Appointments";
            Appointments.TextAlign = ContentAlignment.MiddleLeft;
            // 
            // monthCalendar1
            // 
            monthCalendar1.Location = new Point(45, 56);
            monthCalendar1.Name = "monthCalendar1";
            monthCalendar1.TabIndex = 2;
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(45, 263);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(227, 147);
            richTextBox1.TabIndex = 3;
            richTextBox1.Text = "";
            // 
            // Myname
            // 
            Myname.BackColor = SystemColors.Control;
            Myname.BorderStyle = BorderStyle.None;
            Myname.CausesValidation = false;
            Myname.ForeColor = Color.Blue;
            Myname.Location = new Point(172, 410);
            Myname.Name = "Myname";
            Myname.ReadOnly = true;
            Myname.Size = new Size(100, 16);
            Myname.TabIndex = 0;
            Myname.TabStop = false;
            Myname.Text = "Israel Vasquez";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(316, 431);
            Controls.Add(Myname);
            Controls.Add(richTextBox1);
            Controls.Add(monthCalendar1);
            Controls.Add(Appointments);
            Controls.Add(Calendar);
            Name = "Form1";
            Text = "My Scheduler";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label Calendar;
        private Label Appointments;
        private MonthCalendar monthCalendar1;
        private RichTextBox richTextBox1;
        protected TextBox Myname;
    }
}
