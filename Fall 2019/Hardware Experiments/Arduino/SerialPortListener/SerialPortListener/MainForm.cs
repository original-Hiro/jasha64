using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using SerialPortListener.Serial;
using System.IO;
using System.Windows.Forms.DataVisualization.Charting;

namespace SerialPortListener
{
    public partial class MainForm : Form
    {
        SerialPortManager _spManager;
		const int MaxColCount = 300;
		string PartialData;
        public MainForm()
        {
            InitializeComponent();

            UserInitialization();
        }

      
        private void UserInitialization()
        {
            _spManager = new SerialPortManager();
            SerialSettings mySerialSettings = _spManager.CurrentSerialSettings;
            serialSettingsBindingSource.DataSource = mySerialSettings;
            portNameComboBox.DataSource = mySerialSettings.PortNameCollection;
            baudRateComboBox.DataSource = mySerialSettings.BaudRateCollection;
            dataBitsComboBox.DataSource = mySerialSettings.DataBitsCollection;
            parityComboBox.DataSource = Enum.GetValues(typeof(System.IO.Ports.Parity));
            stopBitsComboBox.DataSource = Enum.GetValues(typeof(System.IO.Ports.StopBits));
			
            _spManager.NewSerialDataRecieved += new EventHandler<SerialDataEventArgs>(_spManager_NewSerialDataRecieved);
            this.FormClosing += new FormClosingEventHandler(MainForm_FormClosing);

			// 初始化电压测量图
			InitChart();
			PartialData = string.Empty;
		}

        
        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            _spManager.Dispose();   
        }

        void _spManager_NewSerialDataRecieved(object sender, SerialDataEventArgs e)
        {
            if (this.InvokeRequired)
            {
                // Using this.Invoke causes deadlock when closing serial port, and BeginInvoke is good practice anyway.
                this.BeginInvoke(new EventHandler<SerialDataEventArgs>(_spManager_NewSerialDataRecieved), new object[] { sender, e });
                return;
            }

            int maxTextLength = 1000; // maximum text length in text box
            if (tbData.TextLength > maxTextLength)
                tbData.Text = tbData.Text.Remove(0, tbData.TextLength - maxTextLength);

            // This application is connected to a GPS sending ASCCI characters, so data is converted to text
            string str = Encoding.ASCII.GetString(e.Data);
            tbData.AppendText(str);
            tbData.ScrollToCaret();

			// 更新电压图
			try
			{
				string cur = str;
				//if (cur.Length != 137) return;
				cur = cur.Substring(8, 126); // 去头去尾
				string[] tmp = cur.Split(',');
				float[] NewVoltage = new float[18];
				for (int i = 0; i < 18; i++) NewVoltage[i] = float.Parse(tmp[i]);
				UpdateChart(NewVoltage);
			}
			catch (Exception)
			{

			}
		}

        // Handles the "Start Listening"-buttom click event
        private void btnStart_Click(object sender, EventArgs e)
        {
			InitChart(); // 声明新对象时，初始化其画图组件
			PartialData = string.Empty;
			_spManager.StartListening();
			_spManager.Send("12\r"); // 开始电压测量
        }

        // Handles the "Stop Listening"-buttom click event
        private void btnStop_Click(object sender, EventArgs e)
        {
            _spManager.StopListening();
        }

		private void InitChart()
		{
			chart1.ChartAreas[0].AxisX.MajorGrid.Enabled = false;
			chart1.ChartAreas[0].AxisX.IsMarginVisible = true;
			chart1.ChartAreas[0].AxisX.Title = "Time";
			chart1.ChartAreas[0].AxisX.TitleForeColor = System.Drawing.Color.Crimson;

			chart1.ChartAreas[0].AxisY.Title = "Voltage";
			chart1.ChartAreas[0].AxisY.TitleForeColor = System.Drawing.Color.Crimson;
			chart1.ChartAreas[0].AxisY.TextOrientation = TextOrientation.Horizontal;
			
			chart1.Series.Clear();
			Series[] VoltageSeries = new Series[18];

			for (int i = 0; i < 18; i++)
			{
				VoltageSeries[i] = new Series("Cell" + (i+1).ToString());
				VoltageSeries[i].ChartType = SeriesChartType.Line;
				VoltageSeries[i].IsValueShownAsLabel = false;
				VoltageSeries[i].Enabled = checkedListBox1.GetItemChecked(i);
				
				//把series添加到chart上
				chart1.Series.Add(VoltageSeries[i]);
			}
		}

		private void UpdateChart(float[] NewValue)
		{
			if (NewValue.Length != 18) throw new Exception("更新图表的参数个数错误");

			if (chart1.Series[0].Points.Count < MaxColCount)
				for (int i = 0; i < 18; i++)
					chart1.Series[i].Points.AddY(NewValue[i]);
			else for (int i = 0; i < 18; i++)
				{
					chart1.Series[i].Points.RemoveAt(0);
					chart1.Series[i].Points.AddY(NewValue[i]);
				}
		}

		private void checkedListBox1_ItemCheck(object sender, ItemCheckEventArgs e)
		{
			chart1.Series[e.Index].Enabled = (e.NewValue == CheckState.Checked ? true : false);
		}
	}
}
