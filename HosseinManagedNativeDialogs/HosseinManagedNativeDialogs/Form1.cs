using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace HosseinNativeDialogs
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            IntPtr windowHandle = NativeDialogs.__HosseinFindProcessWindow(NativeDialogs.__HosseinFindCurrentProcessId());
            this.Text = NativeDialogs.__HosseinFindProcessWindow(NativeDialogs.__HosseinFindCurrentProcessId()) + "=" + this.Handle;
            //NativeDialogs.__HosseinRestoreWindow(this.Handle);
            NativeDialogs.ShowOpenFileDialog();
            NativeDialogs.__HosseinRestoreWindow(this.Handle);
        }
    }
}
