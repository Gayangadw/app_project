import tkinter as tk
from tkinter import filedialog
import os

class ImageToPDFconverter:
    def __init__(self, root):
        self.root = root
        self.image_paths = []
        self.output_pdf_name = tk.StringVar()
        self.selected_images_listbox = tk.Listbox(root, selectmode=tk.MULTIPLE)

        self.initialize_ui()

    def initialize_ui(self):
        title_label = tk.Label(self.root, text="IMAGE TO PDF CONVERTOR", font=("Helvetica", 16, "bold"))
        title_label.pack(pady=10)

        select_images_button = tk.Button(self.root, text="Select Images", command=self.select_images)
        select_images_button.pack(pady=(0, 10))

        self.selected_images_listbox.pack(pady=(0, 10), fill=tk.BOTH, expand=True)

        label = tk.Label(self.root, text="Enter Output PDF name: ")
        label.pack()

        pdf_name_entry = tk.Entry(self.root, textvariable=self.output_pdf_name, width=40, justify='center')
        pdf_name_entry.pack()

        convert_button = tk.Button(self.root, text="Convert to PDF", command=self.convert_images_to_pdf)
        convert_button.pack(pady=(20, 40))

    def select_images(self):
        self.image_paths = filedialog.askopenfilenames(filetypes=[("Image files", "*.jpg;*.png")])
        for path in self.image_paths:
            self.selected_images_listbox.insert(tk.END, os.path.basename(path))

    def convert_images_to_pdf(self):
        output_filename = self.output_pdf_name.get()
        # Add code to convert images to PDF using self.image_paths and output_filename

def main():
    root = tk.Tk()
    root.title("Image to PDF")
    converter = ImageToPDFconverter(root)
    root.geometry("400x600")
    root.mainloop()

if __name__ == "__main__":
    main()
