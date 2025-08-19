from customtkinter import *
from tkinter import Canvas
from serial import *
import json


class Window:
    def __init__(self, Width=5, Height=7):
        self.root = CTk()
        self.root.geometry("600x500")
        self.root.title("pixel Editor")

        self.OffColor = "#545454"
        self.OnColor = "black"

        self.Width = Width
        self.Height = Height

        self.PixelWidth = None
        self.PixelHeight = None

        self.GridWidth = None
        self.GridHeight = None

        self.cord_text = None
        self.pixel = None

        canvasFrame = CTkFrame(self.root, corner_radius=5)
        canvasFrame.place(anchor="nw", relx=0.0, rely=0.0, relwidth=1, relheight=1)

        MainControlFrame = CTkFrame(self.root, corner_radius=5)
        MainControlFrame.place(
            anchor="nw", relx=0.65, rely=0.0, relwidth=1, relheight=1
        )

        ControlFrame = CTkFrame(MainControlFrame, corner_radius=5, fg_color="red")
        ControlFrame.place(anchor="nw", relx=0.0, rely=0.0, relwidth=1, relheight=1)

        OutPutFrame = CTkFrame(MainControlFrame, corner_radius=5, fg_color="blue")
        OutPutFrame.place(anchor="nw", relx=0.0, rely=0.6, relwidth=1, relheight=1)

        self.canvas = Canvas(canvasFrame, bg=self.OffColor)
        self.canvas.place(
            anchor="nw", relx=0.05, rely=0.1, relwidth=0.55, relheight=0.8
        )

        self.canvas.bind("<Motion>", self.DrawCord)
        self.canvas.bind("<Configure>", self.update_winfo)
        self.canvas.bind("<Button-1>", self.pixel_set)
        self.canvas.bind("<Button-3>", self.pixel_reset)

        self.root.mainloop()

    def update_winfo(self, event="<Configure>", resize=True):
        if resize == True:
            self.canvas.delete("all")

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        for c in range(1, self.Width, 1):
            self.canvas.create_line(
                (c * self.PixelWidth),
                0,
                (c * self.PixelWidth),
                self.GridHeight,
                fill="white",
            )

        for r in range(1, self.Height, 1):
            self.canvas.create_line(
                0,
                (r * self.PixelHeight),
                self.GridWidth,
                (r * self.PixelHeight),
                fill="white",
            )

    def DrawCord(self, event="<Motion>"):
        self.canvas.delete(self.cord_text)

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        X = int(event.x / self.PixelWidth)
        Y = int(event.y / self.PixelHeight)

        self.cord_text = self.canvas.create_text(
            ((self.PixelWidth * (X + 1)) - (self.PixelWidth / 2)),
            ((self.PixelHeight * (Y + 1)) - (self.PixelHeight / 2)),
            text=f"{X},{Y}",
            font=("Courier", 20, "bold"),
            fill="white",
        )
        self.update_winfo(resize=False)

    def pixel_set(self, event):

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        X = int(event.x / self.PixelWidth)
        Y = int(event.y / self.PixelHeight)

        self.pixel = self.canvas.create_rectangle(
            (self.PixelWidth * X),
            (self.PixelHeight * Y),
            ((self.PixelWidth * X) + self.PixelWidth),
            ((self.PixelHeight * Y) + self.PixelHeight),
            fill=self.OnColor,
        )

        self.update_winfo(resize=False)

    def pixel_reset(self, event):

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        X = int(event.x / self.PixelWidth)
        Y = int(event.y / self.PixelHeight)

        self.pixel = self.canvas.create_rectangle(
            (self.PixelWidth * X),
            (self.PixelHeight * Y),
            ((self.PixelWidth * X) + self.PixelWidth),
            ((self.PixelHeight * Y) + self.PixelHeight),
            fill=self.OffColor,
        )
        self.update_winfo(resize=False)


def main():

    main = Window()


if __name__ == "__main__":
    main()
