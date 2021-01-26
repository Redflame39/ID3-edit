#pragma once
#include "TagInterface.h"
#include "Frame.h"

namespace ID3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ NewWindow
	/// </summary>
	public ref class NewWindow : public System::Windows::Forms::Form
	{
	public:
		NewWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~NewWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ TIT2;
	private: System::Windows::Forms::TextBox^ TPE1;
	private: System::Windows::Forms::TextBox^ TALB;
	private: System::Windows::Forms::TextBox^ TDRC;
	protected:



	protected:

	protected:





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ TPE2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ TRCK;
	private: System::Windows::Forms::Label^ label6;



	private: System::Windows::Forms::TextBox^ TCOM;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ TCON;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ COMM;

	private: System::Windows::Forms::Label^ label7;

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TIT2 = (gcnew System::Windows::Forms::TextBox());
			this->TPE1 = (gcnew System::Windows::Forms::TextBox());
			this->TALB = (gcnew System::Windows::Forms::TextBox());
			this->TDRC = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TPE2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->TRCK = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->TCOM = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TCON = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->COMM = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// TIT2
			// 
			this->TIT2->Location = System::Drawing::Point(46, 28);
			this->TIT2->Name = L"TIT2";
			this->TIT2->Size = System::Drawing::Size(185, 22);
			this->TIT2->TabIndex = 0;
			this->TIT2->Text = L"<пусто>";
			this->TIT2->TextChanged += gcnew System::EventHandler(this, &NewWindow::textBox1_TextChanged);
			// 
			// TPE1
			// 
			this->TPE1->Location = System::Drawing::Point(46, 76);
			this->TPE1->Name = L"TPE1";
			this->TPE1->Size = System::Drawing::Size(185, 22);
			this->TPE1->TabIndex = 1;
			this->TPE1->Text = L"<пусто>";
			// 
			// TALB
			// 
			this->TALB->Location = System::Drawing::Point(46, 124);
			this->TALB->Name = L"TALB";
			this->TALB->Size = System::Drawing::Size(185, 22);
			this->TALB->TabIndex = 2;
			this->TALB->Text = L"<пусто>";
			// 
			// TDRC
			// 
			this->TDRC->Location = System::Drawing::Point(256, 124);
			this->TDRC->Name = L"TDRC";
			this->TDRC->Size = System::Drawing::Size(185, 22);
			this->TDRC->TabIndex = 3;
			this->TDRC->Text = L"<пусто>";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Title";
			this->label1->Click += gcnew System::EventHandler(this, &NewWindow::label1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(253, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Year";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(48, 104);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Album";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(43, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Artist";
			this->label4->Click += gcnew System::EventHandler(this, &NewWindow::label4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(481, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 46);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewWindow::button1_Click);
			// 
			// TPE2
			// 
			this->TPE2->Location = System::Drawing::Point(256, 29);
			this->TPE2->Name = L"TPE2";
			this->TPE2->Size = System::Drawing::Size(185, 22);
			this->TPE2->TabIndex = 11;
			this->TPE2->Text = L"<пусто>";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(253, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Album performer";
			// 
			// TRCK
			// 
			this->TRCK->Location = System::Drawing::Point(256, 76);
			this->TRCK->Name = L"TRCK";
			this->TRCK->Size = System::Drawing::Size(185, 22);
			this->TRCK->TabIndex = 13;
			this->TRCK->Text = L"<пусто>";
			this->TRCK->TextChanged += gcnew System::EventHandler(this, &NewWindow::TRCK_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(253, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Number";
			// 
			// TCOM
			// 
			this->TCOM->Location = System::Drawing::Point(456, 28);
			this->TCOM->Name = L"TCOM";
			this->TCOM->Size = System::Drawing::Size(185, 22);
			this->TCOM->TabIndex = 17;
			this->TCOM->Text = L"<пусто>";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(453, 8);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 17);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Composer";
			// 
			// TCON
			// 
			this->TCON->Location = System::Drawing::Point(456, 76);
			this->TCON->Name = L"TCON";
			this->TCON->Size = System::Drawing::Size(185, 22);
			this->TCON->TabIndex = 19;
			this->TCON->Text = L"<пусто>";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(453, 56);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 17);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Genre";
			// 
			// COMM
			// 
			this->COMM->Location = System::Drawing::Point(46, 167);
			this->COMM->Name = L"COMM";
			this->COMM->Size = System::Drawing::Size(185, 22);
			this->COMM->TabIndex = 21;
			this->COMM->Text = L"<пусто>";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(48, 149);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 17);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Comment";
			// 
			// NewWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 202);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->COMM);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->TCON);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->TCOM);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->TRCK);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->TPE2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TDRC);
			this->Controls->Add(this->TALB);
			this->Controls->Add(this->TPE1);
			this->Controls->Add(this->TIT2);
			this->Name = L"NewWindow";
			this->Text = L"NewWindow";
			this->ResumeLayout(false);
			this->PerformLayout();

			initFields();

		}

		void initFields() {
			TIT2->Text = gcnew System::String(TagInterface::currentTag.getData("TIT2").c_str(), 0, TagInterface::currentTag.getData("TIT2").length(), System::Text::UTF8Encoding::UTF8);
			TPE1->Text = gcnew System::String(TagInterface::currentTag.getData("TPE1").c_str(), 0, TagInterface::currentTag.getData("TPE1").length(), System::Text::UTF8Encoding::UTF8);
			TPE2->Text = gcnew System::String(TagInterface::currentTag.getData("TPE2").c_str(), 0, TagInterface::currentTag.getData("TPE2").length(), System::Text::UTF8Encoding::UTF8);
			TALB->Text = gcnew System::String(TagInterface::currentTag.getData("TALB").c_str(), 0, TagInterface::currentTag.getData("TALB").length(), System::Text::UTF8Encoding::UTF8);
			TDRC->Text = gcnew System::String(TagInterface::currentTag.getData("TDRC").c_str(), 0, TagInterface::currentTag.getData("TDRC").length(), System::Text::UTF8Encoding::UTF8);
			TRCK->Text = gcnew System::String(TagInterface::currentTag.getData("TRCK").c_str(), 0, TagInterface::currentTag.getData("TRCK").length(), System::Text::UTF8Encoding::UTF8);
			TCOM->Text = gcnew System::String(TagInterface::currentTag.getData("TCOM").c_str(), 0, TagInterface::currentTag.getData("TCOM").length(), System::Text::UTF8Encoding::UTF8);
			TCON->Text = gcnew System::String(TagInterface::currentTag.getData("TCON").c_str(), 0, TagInterface::currentTag.getData("TCON").length(), System::Text::UTF8Encoding::UTF8);
			COMM->Text = gcnew System::String(TagInterface::currentTag.getData("COMM").c_str(), 0, TagInterface::currentTag.getData("COMM").length(), System::Text::UTF8Encoding::UTF8);
		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		MessageBox^ mb;

		if (!TagEdit::checkValidInput(TIT2->Text, "TIT2"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TPE1->Text, "TPE1"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TPE2->Text, "TPE2"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TALB->Text, "TALB"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TDRC->Text, "TDRC"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TRCK->Text, "TRCK"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TCOM->Text, "TCOM"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(TCON->Text, "TCON"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (!TagEdit::checkValidInput(COMM->Text, "COMM"))
		{
			mb->Show("Invalid input!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (String::IsNullOrEmpty(TIT2->Text) == false)
			TagInterface::currentTag.addFrame("TIT2", TIT2->Text);

		if (String::IsNullOrEmpty(TPE1->Text) == false)
			TagInterface::currentTag.addFrame("TPE1", TPE1->Text);

		if (String::IsNullOrEmpty(TPE2->Text) == false)
			TagInterface::currentTag.addFrame("TPE2", TPE2->Text);

		if (String::IsNullOrEmpty(TALB->Text) == false)
			TagInterface::currentTag.addFrame("TALB", TALB->Text);

		if (String::IsNullOrEmpty(TDRC->Text) == false)
			TagInterface::currentTag.addFrame("TDRC", TDRC->Text);

		if (String::IsNullOrEmpty(TRCK->Text) == false)
			TagInterface::currentTag.addFrame("TRCK", TRCK->Text);

		if (String::IsNullOrEmpty(TCOM->Text) == false)
			TagInterface::currentTag.addFrame("TCOM", TCOM->Text);

		if (String::IsNullOrEmpty(TCON->Text) == false)
			TagInterface::currentTag.addFrame("TCON", TCON->Text);

		if (String::IsNullOrEmpty(COMM->Text) == false)
			TagInterface::currentTag.addFrame("COMM", COMM->Text);

		System::Windows::Forms::DialogResult result;

		if (TagInterface::currentTag.editedFrames.size() == 0)
			result = mb->Show("You haven't set tag values. Tag will be removed from MP3-file.\nAgree?", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		if (result == System::Windows::Forms::DialogResult::Cancel)
			return;
		TagInterface::currentTag.writeData();
		mb->Show("Success", "Success", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		Close();

	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void TRCK_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
