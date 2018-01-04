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

        [DllImport("Math.dll", EntryPoint = "?Mul@MathDll@1@SAPBDPBD0@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Mul(String a, String b);

        [DllImport("Math.dll", EntryPoint = "?Add@MathDll@1@SAPBDPBD0@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Add(String a, String b);

        [DllImport("Math.dll", EntryPoint = "?Sub@MathDll@1@SAPBDPBD0@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Sub(String a, String b);

        [DllImport("Math.dll", EntryPoint = "?Div@MathDll@1@SAPBDPBD0@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Div(String a, String b);

        [DllImport("Math.dll", EntryPoint = "?Pow@MathDll@1@SAPBDPBD0@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static IntPtr Pow(String a, String b);


        String s;
        String first = "";
        String second = "";
        String oper = "0";
        String save="";

        public Form1()
        {
            InitializeComponent();
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "1";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "1";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "2";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "2";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "3";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "3";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "4";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "4";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "5";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "5";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "6";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "6";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "7";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "7";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "8";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "8";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == "0")
                {
                    first = "";
                }
                first += "9";
                s = first;
            }
            else
            {
                if (second == "0")
                {
                    second = "";
                }
                second += "9";
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                if (first == null || first != "0")
                {
                    first += "0";
                    s += "0";
                }
            }
            else
            {
                if (second == null || second != "0")
                {
                    second += "0";
                    s += "0";
                }
            }
            textBoxCalc.Text = s;
        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            Boolean wrong = false;
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "txt文件(*.txt)|*.txt";
            fileDialog.ShowDialog();
            try
            {
                String file = fileDialog.FileName;
                StreamReader sr = new StreamReader(file);
                String temp;
                if ((temp = sr.ReadLine()) != null)
                {
                    MessageBox.Show(temp);
                    int bit = 0;
                    first = "";
                    second = "";
                    for (int i = 0; i < temp.Length; ++i)
                    {
                        if (temp[i] == '+' || temp[i] == '-' || temp[i] == '*' || temp[i] == '/' || temp[i] == '^')
                        {
                            bit = i;
                            break;
                        }
                        if (temp[i] != ' ')
                        {
                            if (temp[i] >= '0' && temp[i] <= '9')
                            {
                                first += temp[i];
                            }
                            else
                            {
                                MessageBox.Show("文本读取错误，请确认文本信息");
                                wrong = true;
                                break;
                            }
                        }
                    }
                    if (!wrong)
                    {
                        oper = temp[bit].ToString();
                        for (int i = bit + 1; i < temp.Length; ++i)
                        {
                            if (temp[i] != '=' || temp[i] != ' ')
                            {
                                if (temp[i] >= '0' && temp[i] <= '9')
                                {
                                    second += temp[i];
                                }
                                else
                                {
                                    MessageBox.Show("文本读取错误，请确认文本信息");
                                    wrong = true;
                                    break;
                                }
                            }
                        }
                        if (!wrong)
                        {
                            btnEqu_Click(sender, e);
                        }
                    }
                    first = "";
                    second = "";
                    oper = "0";
                    s = "";
                    if (wrong)
                    { 
                        textBoxCalc.Text = "";
                    }
                }
                else
                {
                    MessageBox.Show("文件为空");
                }
                sr.Close();
                
            }
            catch { }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                SaveFileDialog fileDialog = new SaveFileDialog();
                fileDialog.AddExtension = true;
                fileDialog.RestoreDirectory = true;
                fileDialog.Title = "另存为";
                fileDialog.Filter = "txt文件(*.txt)|*txt";
                fileDialog.ShowDialog();
                String file = fileDialog.FileName;
                String last = file.Substring(file.Length - 4);
                if (last == ".txt" || last == ".TXT")
                {
                }
                else
                {
                    file += ".txt";
                }
                StreamWriter sw = new StreamWriter(file);
                sw.WriteLine(save);
                sw.Close();
            }
            catch
            {
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if(oper=="0")
            {
                if (first == "")
                {
                    first = "0";
                }
                s = first + "\r\n+\r\n";
                textBoxCalc.Text = s;
                oper = "+";
            }

        }

        private void btnSub_Click(object sender, EventArgs e)
        {
            if (oper=="0")
            {
                if (first == "")
                {
                    first = "0";
                }
                s = first + "\r\n-\r\n";
                textBoxCalc.Text = s;
                oper = "-";
            }
        }

        private void btnMul_Click(object sender, EventArgs e)
        {
            if (oper=="0")
            {
                if (first == "")
                {
                    first = "0";
                }
                s = first + "\r\n*\r\n";
                textBoxCalc.Text = s;
                oper = "*";
            }
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            if (oper=="0")
            {
                if (first == "")
                {
                    first = "0";
                }
                s = first + "\r\n/\r\n";
                textBoxCalc.Text = s;
                oper = "/";
            }
        }

        private void btnInd_Click(object sender, EventArgs e)
        {
            if (oper=="0")
            {
                if (first == "")
                {
                    first = "0";
                }
                s = first + "\r\n^\r\n";
                textBoxCalc.Text = s;
                oper = "^";
            }
        }

        private void btnEqu_Click(object sender, EventArgs e)
        {
            if (oper == "0")
            {
                MessageBox.Show("输入错误");
            }
            else
            {
                if (second == "")
                {
                    second = "0";
                }
                String result = "";
                s = first + "\r\n"+oper+"\r\n" + second;
                switch (oper)
                {
                    case "+":
                        IntPtr pAdd = Add(first, second);
                        result = Marshal.PtrToStringAnsi(pAdd);
                        break;
                    case "-":
                        IntPtr pSub = Sub(first, second);
                        result = Marshal.PtrToStringAnsi(pSub);
                        break;
                    case "*":
                        IntPtr pMul = Mul(first, second);
                        result = Marshal.PtrToStringAnsi(pMul);
                        break;
                    case "/":
                        if (second == "0")
                        {
                            MessageBox.Show("除数不能为零");
                        }
                        else
                        {
                            IntPtr pDiv = Div(first, second);
                            result = Marshal.PtrToStringAnsi(pDiv);
                        }
                        break;
                    case "^":
                        IntPtr pPow = Pow(first, second);
                        result = Marshal.PtrToStringAnsi(pPow);
                        break;
                }
                if (oper == "/" && second == "0")
                {
                    s = "";
                }
                else
                {
                    s += "\r\n=\r\n" + result;
                }
                textBoxCalc.Text = s;
                save = s;
                oper = "0";
                first = "";
                second = "";
                s = "";
            }
        }

        private void btnClean_Click(object sender, EventArgs e)
        {
            if (first != "")
            {
                if (oper != "0")
                {
                    if (second != "")
                    {
                        second = second.Substring(0, second.Length - 1);
                    }
                    else
                    {
                        oper = "0";
                    }
                }
                else
                {
                    first = first.Substring(0, first.Length - 1);
                }
            }
            if (oper == "0")
            {
                s = first;
            }
            else
            {
                s = first + "\r\n" + oper + "\r\n" + second;
            }
            textBoxCalc.Text = s;
        }
    }
}
