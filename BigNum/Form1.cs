using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace BigNum
{
    public partial class Form1 : Form
    {

        [DllImport("Math.dll", EntryPoint = "?Mul@MathDll@1@SAPBDPBD0HH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Mul(String a, String b,int len_a,int len_b);

        [DllImport("Math.dll", EntryPoint = "?Add@MathDll@1@SAPBDPBD0HH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Add(String a, String b, int len_a, int len_b);

        [DllImport("Math.dll", EntryPoint = "?Sub@MathDll@1@SAPBDPBD0HH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Sub(String a, String b, int len_a, int len_b);

        [DllImport("Math.dll", EntryPoint = "?Div@MathDll@1@SAPBDPBD0HH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Div(String a, String b, int len_a, int len_b);

        [DllImport("Math.dll", EntryPoint = "?Pow@MathDll@1@SAPBDPBD0HH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Pow(String a, String b, int len_a, int len_b);


        String s;
        String num;
        Boolean b = false;
        int oper = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            s += "1";
            textBoxCalc.Text = s;
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            s += "2";
            textBoxCalc.Text = s;
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            s += "3";
            textBoxCalc.Text = s;
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            s += "4";
            textBoxCalc.Text = s;
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            s += "5";
            textBoxCalc.Text = s;
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            s += "6";
            textBoxCalc.Text = s;
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            s += "7";
            textBoxCalc.Text = s;
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            s += "8";
            textBoxCalc.Text = s;
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            s += "9";
            textBoxCalc.Text = s;
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            s += "0";
            textBoxCalc.Text = s;
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "txt文件(*.txt)|*.txt";
            fileDialog.ShowDialog();
            String file = fileDialog.FileName;
            StreamReader sr = new StreamReader(file);
            String temp;
            if((temp = sr.ReadLine()) != null)
            {
                num = temp;
            }
            sr.Close();
            
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            SaveFileDialog fileDialog = new SaveFileDialog();
            fileDialog.Title = "另存为";
            fileDialog.Filter = "txt文件(*.txt)|*txt";
            fileDialog.ShowDialog();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if(!b)
            {
                s += "+";
                textBoxCalc.Text = s;
                b = true;
                oper = 1;
            }
        }

        private void btnSub_Click(object sender, EventArgs e)
        {
            if (!b)
            {
                s += "-";
                textBoxCalc.Text = s;
                b = true;
                oper = 2;
            }
        }

        private void btnMul_Click(object sender, EventArgs e)
        {
            if (!b)
            {
                s += "*";
                textBoxCalc.Text = s;
                b = true;
                oper = 3;
            }
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            if (!b)
            {
                s += "/";
                textBoxCalc.Text = s;
                b = true;
                oper = 4;
            }
        }

        private void btnInd_Click(object sender, EventArgs e)
        {
            if (!b)
            {
                s += "^";
                textBoxCalc.Text = s;
                b = true;
                oper = 5;
            }
        }

        private void btnEqu_Click(object sender, EventArgs e)
        {
            if (oper == 0)
            {
                MessageBox.Show("输入错误");
            }
            else {
                String first = "", second = "";
                String result = "";
                int bit = 0;
                for(int i = 0; i < s.Length; ++i)
                {
                    if(s[i]=='+'|| s[i] == '-'|| s[i] == '*'|| s[i] == '/'|| s[i] == '^')
                    {
                        bit = i;
                        break;
                    }
                    first += s[i];
                }
                for(int i = bit + 1; i < s.Length; ++i)
                {
                    second += s[i];
                }
                switch (oper)
                {
                    case 1:
                        IntPtr pAdd = Add(first, second, first.Length, second.Length);
                        result = Marshal.PtrToStringAnsi(pAdd);
                        s += "=" + result;
                        textBoxCalc.Text = s;
                        break;
                    case 2:
                        IntPtr pSub = Sub(first, second, first.Length, second.Length);
                        result = Marshal.PtrToStringAnsi(pSub);
                        s += "=" + result;
                        textBoxCalc.Text = s;
                        break;
                    case 3:
                        IntPtr pMul = Mul(first, second, first.Length, second.Length);
                        result = Marshal.PtrToStringAnsi(pMul);
                        s += "=" + result;
                        textBoxCalc.Text = s;
                        break;
                    case 4:
                        IntPtr pDiv = Div(first, second, first.Length, second.Length);
                        result = Marshal.PtrToStringAnsi(pDiv);
                        s += "=" + result;
                        textBoxCalc.Text = s;
                        break;
                    case 5:
                        IntPtr pPow = Pow(first, second, first.Length, second.Length);
                        result = Marshal.PtrToStringAnsi(pPow);
                        s += "=" + result;
                        textBoxCalc.Text = s;
                        break;
                }
            }
        }
    }
}
