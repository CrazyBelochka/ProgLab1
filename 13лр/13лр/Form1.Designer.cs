
namespace _13лр
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.peopleS = new System.Windows.Forms.NumericUpDown();
            this.doc = new System.Windows.Forms.NumericUpDown();
            this.peopleH = new System.Windows.Forms.NumericUpDown();
            this.simulation = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.model = new System.Windows.Forms.Label();
            this.add_people = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.peopleS)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.doc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.peopleH)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(177, 24);
            this.label1.TabIndex = 0;
            this.label1.Text = "Зараженные люди";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(245, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(155, 24);
            this.label2.TabIndex = 1;
            this.label2.Text = "Здоровые люди";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(486, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(86, 24);
            this.label3.TabIndex = 2;
            this.label3.Text = "Доктора";
            // 
            // peopleS
            // 
            this.peopleS.Location = new System.Drawing.Point(12, 36);
            this.peopleS.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.peopleS.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.peopleS.Name = "peopleS";
            this.peopleS.Size = new System.Drawing.Size(176, 20);
            this.peopleS.TabIndex = 3;
            this.peopleS.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // doc
            // 
            this.doc.Location = new System.Drawing.Point(486, 36);
            this.doc.Maximum = new decimal(new int[] {
            7,
            0,
            0,
            0});
            this.doc.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.doc.Name = "doc";
            this.doc.Size = new System.Drawing.Size(176, 20);
            this.doc.TabIndex = 4;
            this.doc.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // peopleH
            // 
            this.peopleH.Location = new System.Drawing.Point(245, 36);
            this.peopleH.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.peopleH.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.peopleH.Name = "peopleH";
            this.peopleH.Size = new System.Drawing.Size(177, 20);
            this.peopleH.TabIndex = 5;
            this.peopleH.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // simulation
            // 
            this.simulation.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.simulation.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.simulation.Location = new System.Drawing.Point(248, 360);
            this.simulation.Name = "simulation";
            this.simulation.Size = new System.Drawing.Size(288, 78);
            this.simulation.TabIndex = 6;
            this.simulation.Text = "Следущее движение модели";
            this.simulation.UseVisualStyleBackColor = true;
            this.simulation.Click += new System.EventHandler(this.button1_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(352, 196);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(70, 20);
            this.label4.TabIndex = 10;
            this.label4.Text = "Модель";
            // 
            // model
            // 
            this.model.AutoSize = true;
            this.model.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.model.Location = new System.Drawing.Point(273, 283);
            this.model.Name = "model";
            this.model.Size = new System.Drawing.Size(216, 20);
            this.model.TabIndex = 11;
            this.model.Text = "_______________________";
            // 
            // add_people
            // 
            this.add_people.Location = new System.Drawing.Point(16, 87);
            this.add_people.Name = "add_people";
            this.add_people.Size = new System.Drawing.Size(75, 23);
            this.add_people.TabIndex = 12;
            this.add_people.Text = "Добавить";
            this.add_people.UseVisualStyleBackColor = true;
            this.add_people.Click += new System.EventHandler(this.button5_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.add_people);
            this.Controls.Add(this.model);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.simulation);
            this.Controls.Add(this.peopleH);
            this.Controls.Add(this.doc);
            this.Controls.Add(this.peopleS);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.peopleS)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.doc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.peopleH)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown peopleS;
        private System.Windows.Forms.NumericUpDown doc;
        private System.Windows.Forms.NumericUpDown peopleH;
        private System.Windows.Forms.Button simulation;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label model;
        private System.Windows.Forms.Button add_people;
    }
}

