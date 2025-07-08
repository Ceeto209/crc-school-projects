// Name: Israel Vasquez
// Assignment#: A3
// File Name: Form1.cs
// Purpose: Initialize the form component and method for selecting states
// Course: CISP 405 SU25

namespace CISP405A3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        // Method for selecting states and checking if there are states left to select
        private void comboBoxStates_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxForStates.SelectedIndex >= 0) // if comoboBox has states to select
            {
                string selectedState = comboBoxForStates.SelectedItem.ToString(); // when a state is clicked
                comboBoxForStates.Items.Remove(selectedState); // remove the selected state from combobox
                listBoxForSelectedStates.Items.Add(selectedState); // add selected state to listbox

                if (comboBoxForStates.Items.Count == 0) // if there are no more states left to select notify and close application
                {
                    MessageBox.Show("There are no more states in the ComboBox.", "Empty", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    Application.Exit();
                }
            }
        }
    }
}
