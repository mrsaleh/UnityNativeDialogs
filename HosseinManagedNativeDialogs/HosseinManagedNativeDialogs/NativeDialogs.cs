using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace HosseinNativeDialogs
{

    public class NativeDialogs
    {
        [DllImport(@"NativeDialogs.dll",EntryPoint = "HosseinOpenFile", CallingConvention = CallingConvention.StdCall,CharSet =CharSet.Unicode)]
        public extern static IntPtr __HosseinOpenFile(IntPtr _parentHandle);

        [DllImport(@"NativeDialogs.dll", EntryPoint = "HosseinFindProcessWindow", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static IntPtr __HosseinFindProcessWindow(UInt32 _processId);

        [DllImport(@"NativeDialogs.dll", EntryPoint = "HosseinFindCurrentProcessId", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static UInt32 __HosseinFindCurrentProcessId();

        [DllImport(@"NativeDialogs.dll", EntryPoint = "HosseinRestoreWindow", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static void __HosseinRestoreWindow(IntPtr _hwnd);

        [DllImport(@"NativeDialogs.dll", EntryPoint = "HosseinShowWindow", CallingConvention = CallingConvention.StdCall, CharSet = CharSet.Unicode)]
        public extern static void __HosseinShowWindow(IntPtr _hwnd);

        public static string ShowOpenFileDialog(IntPtr _parentHandle)
        {
            IntPtr s = __HosseinOpenFile(_parentHandle);
            string str = Marshal.PtrToStringUni(s);
            return str;
        }

        public static string ShowOpenFileDialog()
        {
            return ShowOpenFileDialog( __HosseinFindProcessWindow(__HosseinFindCurrentProcessId()));
        }

        /*
        [STAThread]
        static int Main()
        {
            //IntPtr filename;


            Application.Run(new Form1());
            return 0;
        }

    */
        
        
    }
}
