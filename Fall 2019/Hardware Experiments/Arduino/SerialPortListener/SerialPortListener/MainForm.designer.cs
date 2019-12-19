namespace SerialPortListener
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			this.components = new System.ComponentModel.Container();
			System.Windows.Forms.Label baudRateLabel;
			System.Windows.Forms.Label dataBitsLabel;
			System.Windows.Forms.Label parityLabel;
			System.Windows.Forms.Label portNameLabel;
			System.Windows.Forms.Label stopBitsLabel;
			System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
			System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
			System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
			this.baudRateComboBox = new System.Windows.Forms.ComboBox();
			this.serialSettingsBindingSource = new System.Windows.Forms.BindingSource(this.components);
			this.dataBitsComboBox = new System.Windows.Forms.ComboBox();
			this.parityComboBox = new System.Windows.Forms.ComboBox();
			this.portNameComboBox = new System.Windows.Forms.ComboBox();
			this.stopBitsComboBox = new System.Windows.Forms.ComboBox();
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.btnStart = new System.Windows.Forms.Button();
			this.btnStop = new System.Windows.Forms.Button();
			this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
			this.tbData = new System.Windows.Forms.TextBox();
			this.checkedListBox1 = new System.Windows.Forms.CheckedListBox();
			baudRateLabel = new System.Windows.Forms.Label();
			dataBitsLabel = new System.Windows.Forms.Label();
			parityLabel = new System.Windows.Forms.Label();
			portNameLabel = new System.Windows.Forms.Label();
			stopBitsLabel = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).BeginInit();
			this.groupBox1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
			this.SuspendLayout();
			// 
			// baudRateLabel
			// 
			baudRateLabel.AutoSize = true;
			baudRateLabel.Location = new System.Drawing.Point(13, 68);
			baudRateLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			baudRateLabel.Name = "baudRateLabel";
			baudRateLabel.Size = new System.Drawing.Size(87, 15);
			baudRateLabel.TabIndex = 1;
			baudRateLabel.Text = "Baud Rate:";
			// 
			// dataBitsLabel
			// 
			dataBitsLabel.AutoSize = true;
			dataBitsLabel.Location = new System.Drawing.Point(13, 99);
			dataBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			dataBitsLabel.Name = "dataBitsLabel";
			dataBitsLabel.Size = new System.Drawing.Size(87, 15);
			dataBitsLabel.TabIndex = 3;
			dataBitsLabel.Text = "Data Bits:";
			// 
			// parityLabel
			// 
			parityLabel.AutoSize = true;
			parityLabel.Location = new System.Drawing.Point(13, 130);
			parityLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			parityLabel.Name = "parityLabel";
			parityLabel.Size = new System.Drawing.Size(63, 15);
			parityLabel.TabIndex = 5;
			parityLabel.Text = "Parity:";
			// 
			// portNameLabel
			// 
			portNameLabel.AutoSize = true;
			portNameLabel.Location = new System.Drawing.Point(13, 37);
			portNameLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			portNameLabel.Name = "portNameLabel";
			portNameLabel.Size = new System.Drawing.Size(87, 15);
			portNameLabel.TabIndex = 7;
			portNameLabel.Text = "Port Name:";
			// 
			// stopBitsLabel
			// 
			stopBitsLabel.AutoSize = true;
			stopBitsLabel.Location = new System.Drawing.Point(13, 162);
			stopBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
			stopBitsLabel.Name = "stopBitsLabel";
			stopBitsLabel.Size = new System.Drawing.Size(87, 15);
			stopBitsLabel.TabIndex = 9;
			stopBitsLabel.Text = "Stop Bits:";
			// 
			// baudRateComboBox
			// 
			this.baudRateComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "BaudRate", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.baudRateComboBox.FormattingEnabled = true;
			this.baudRateComboBox.Location = new System.Drawing.Point(103, 65);
			this.baudRateComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.baudRateComboBox.Name = "baudRateComboBox";
			this.baudRateComboBox.Size = new System.Drawing.Size(160, 23);
			this.baudRateComboBox.TabIndex = 2;
			// 
			// serialSettingsBindingSource
			// 
			this.serialSettingsBindingSource.DataSource = typeof(SerialPortListener.Serial.SerialSettings);
			// 
			// dataBitsComboBox
			// 
			this.dataBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "DataBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.dataBitsComboBox.FormattingEnabled = true;
			this.dataBitsComboBox.Location = new System.Drawing.Point(103, 96);
			this.dataBitsComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.dataBitsComboBox.Name = "dataBitsComboBox";
			this.dataBitsComboBox.Size = new System.Drawing.Size(160, 23);
			this.dataBitsComboBox.TabIndex = 4;
			// 
			// parityComboBox
			// 
			this.parityComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "Parity", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.parityComboBox.FormattingEnabled = true;
			this.parityComboBox.Location = new System.Drawing.Point(103, 127);
			this.parityComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.parityComboBox.Name = "parityComboBox";
			this.parityComboBox.Size = new System.Drawing.Size(160, 23);
			this.parityComboBox.TabIndex = 6;
			// 
			// portNameComboBox
			// 
			this.portNameComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "PortName", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.portNameComboBox.FormattingEnabled = true;
			this.portNameComboBox.Location = new System.Drawing.Point(103, 33);
			this.portNameComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.portNameComboBox.Name = "portNameComboBox";
			this.portNameComboBox.Size = new System.Drawing.Size(160, 23);
			this.portNameComboBox.TabIndex = 8;
			// 
			// stopBitsComboBox
			// 
			this.stopBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "StopBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
			this.stopBitsComboBox.FormattingEnabled = true;
			this.stopBitsComboBox.Location = new System.Drawing.Point(103, 158);
			this.stopBitsComboBox.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.stopBitsComboBox.Name = "stopBitsComboBox";
			this.stopBitsComboBox.Size = new System.Drawing.Size(160, 23);
			this.stopBitsComboBox.TabIndex = 10;
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.baudRateComboBox);
			this.groupBox1.Controls.Add(baudRateLabel);
			this.groupBox1.Controls.Add(this.stopBitsComboBox);
			this.groupBox1.Controls.Add(stopBitsLabel);
			this.groupBox1.Controls.Add(dataBitsLabel);
			this.groupBox1.Controls.Add(this.portNameComboBox);
			this.groupBox1.Controls.Add(this.dataBitsComboBox);
			this.groupBox1.Controls.Add(portNameLabel);
			this.groupBox1.Controls.Add(parityLabel);
			this.groupBox1.Controls.Add(this.parityComboBox);
			this.groupBox1.Location = new System.Drawing.Point(147, 14);
			this.groupBox1.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Padding = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.groupBox1.Size = new System.Drawing.Size(289, 197);
			this.groupBox1.TabIndex = 11;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Serial Port Settings";
			// 
			// btnStart
			// 
			this.btnStart.Location = new System.Drawing.Point(203, 248);
			this.btnStart.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnStart.Name = "btnStart";
			this.btnStart.Size = new System.Drawing.Size(113, 27);
			this.btnStart.TabIndex = 12;
			this.btnStart.Text = "Start listening";
			this.btnStart.UseVisualStyleBackColor = true;
			this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
			// 
			// btnStop
			// 
			this.btnStop.Location = new System.Drawing.Point(323, 248);
			this.btnStop.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.btnStop.Name = "btnStop";
			this.btnStop.Size = new System.Drawing.Size(113, 27);
			this.btnStop.TabIndex = 12;
			this.btnStop.Text = "Stop listening";
			this.btnStop.UseVisualStyleBackColor = true;
			this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
			// 
			// chart1
			// 
			this.chart1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.chart1.BorderlineColor = System.Drawing.Color.Gray;
			this.chart1.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid;
			chartArea1.Name = "ChartArea1";
			this.chart1.ChartAreas.Add(chartArea1);
			legend1.Name = "Legend1";
			this.chart1.Legends.Add(legend1);
			this.chart1.Location = new System.Drawing.Point(463, 14);
			this.chart1.Name = "chart1";
			series1.ChartArea = "ChartArea1";
			series1.Legend = "Legend1";
			series1.Name = "Series1";
			this.chart1.Series.Add(series1);
			this.chart1.Size = new System.Drawing.Size(564, 515);
			this.chart1.TabIndex = 14;
			this.chart1.Text = "chart1";
			// 
			// tbData
			// 
			this.tbData.Location = new System.Drawing.Point(16, 300);
			this.tbData.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.tbData.Multiline = true;
			this.tbData.Name = "tbData";
			this.tbData.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
			this.tbData.Size = new System.Drawing.Size(420, 229);
			this.tbData.TabIndex = 13;
			// 
			// checkedListBox1
			// 
			this.checkedListBox1.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
			this.checkedListBox1.CheckOnClick = true;
			this.checkedListBox1.FormattingEnabled = true;
			this.checkedListBox1.Items.AddRange(new object[] {
            "Cell1",
            "Cell2",
            "Cell3",
            "Cell4",
            "Cell5",
            "Cell6",
            "Cell7",
            "Cell8",
            "Cell9",
            "Cell10",
            "Cell11",
            "Cell12",
            "Cell13",
            "Cell14",
            "Cell15",
            "Cell16",
            "Cell17",
            "Cell18"});
			this.checkedListBox1.Location = new System.Drawing.Point(907, 165);
			this.checkedListBox1.Name = "checkedListBox1";
			this.checkedListBox1.Size = new System.Drawing.Size(120, 364);
			this.checkedListBox1.TabIndex = 15;
			this.checkedListBox1.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.checkedListBox1_ItemCheck);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1039, 548);
			this.Controls.Add(this.checkedListBox1);
			this.Controls.Add(this.chart1);
			this.Controls.Add(this.tbData);
			this.Controls.Add(this.btnStop);
			this.Controls.Add(this.btnStart);
			this.Controls.Add(this.groupBox1);
			this.Margin = new System.Windows.Forms.Padding(4, 3, 4, 3);
			this.Name = "MainForm";
			this.Text = "RSLog Plus";
			((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).EndInit();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.BindingSource serialSettingsBindingSource;
        private System.Windows.Forms.ComboBox baudRateComboBox;
        private System.Windows.Forms.ComboBox dataBitsComboBox;
        private System.Windows.Forms.ComboBox parityComboBox;
        private System.Windows.Forms.ComboBox portNameComboBox;
        private System.Windows.Forms.ComboBox stopBitsComboBox;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnStop;
		private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
		private System.Windows.Forms.TextBox tbData;
		private System.Windows.Forms.CheckedListBox checkedListBox1;
	}
}

