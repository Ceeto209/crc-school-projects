// Name: Israel Vasquez
// Assignment#: A3
// File Name: Form1.Designer.cs
// Purpose: Store the code for the From1 Designer, all the properties added/created will be located in this file.
// Course: CISP 405 SU25

namespace CISP405A3
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
            selectStateLabel = new Label();
            comboBoxForStates = new ComboBox();
            listBoxForSelectedStates = new ListBox();
            SuspendLayout();
            // 
            // selectStateLabel
            // 
            selectStateLabel.BackColor = SystemColors.Control;
            selectStateLabel.BorderStyle = BorderStyle.Fixed3D;
            selectStateLabel.Location = new Point(21, 21);
            selectStateLabel.Name = "selectStateLabel";
            selectStateLabel.Size = new Size(150, 17);
            selectStateLabel.TabIndex = 0;
            selectStateLabel.Text = "Select a State";
            selectStateLabel.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // comboBoxForStates
            // 
            comboBoxForStates.DropDownHeight = 120;
            comboBoxForStates.FormattingEnabled = true;
            comboBoxForStates.IntegralHeight = false;
            comboBoxForStates.ItemHeight = 15;
            comboBoxForStates.Items.AddRange(new object[] { "New Jersey", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Maryland", "Massachusetts", "Michigan", "Wisconsin", "Wyoming", "Oregon", "Pennsylvania", "Rhode Island" });
            comboBoxForStates.Location = new Point(21, 50);
            comboBoxForStates.Name = "comboBoxForStates";
            comboBoxForStates.Size = new Size(150, 23);
            comboBoxForStates.TabIndex = 1;
            comboBoxForStates.SelectedIndexChanged += comboBoxStates_SelectedIndexChanged;
            // 
            // listBoxForSelectedStates
            // 
            listBoxForSelectedStates.FormattingEnabled = true;
            listBoxForSelectedStates.ItemHeight = 15;
            listBoxForSelectedStates.Location = new Point(21, 88);
            listBoxForSelectedStates.Name = "listBoxForSelectedStates";
            listBoxForSelectedStates.Size = new Size(150, 139);
            listBoxForSelectedStates.TabIndex = 2;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(193, 250);
            Controls.Add(listBoxForSelectedStates);
            Controls.Add(comboBoxForStates);
            Controls.Add(selectStateLabel);
            Name = "Form1";
            Text = "States";
            Load += Form1_Load;
            ResumeLayout(false);
        }

        #endregion

        private Label selectStateLabel;
        private ComboBox comboBoxForStates;
        private ListBox listBoxForSelectedStates;
    }
}
