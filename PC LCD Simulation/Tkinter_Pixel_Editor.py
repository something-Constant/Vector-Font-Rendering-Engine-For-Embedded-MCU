from customtkinter import *
from tkinter import Canvas, messagebox, font
import secrets
import random


class Window:

    def __init__(self, Width=5, Height=7):
        set_default_color_theme("dark-blue")

        self.root = CTk()
        self.root.geometry("600x500")
        self.root.title("pixel Editor")

        self.OffColor = "#545454"
        self.OnColor = "black"
        self.randcolor = "#" + secrets.token_hex(3)

        self.Width = Width
        self.Height = Height

        self.PixelWidth = None
        self.PixelHeight = None

        self.GridWidth = None
        self.GridHeight = None

        self.cord_text = None
        self.pixel = None

        self.x0 = None
        self.y0 = None
        self.x1 = None
        self.y1 = None
        self.lineflag = 0
        self.cordpoint = []

        canvasFrame = CTkFrame(self.root, corner_radius=5)
        canvasFrame.place(anchor="nw", relx=0.0, rely=0.0, relwidth=1, relheight=1)

        MainControlFrame = CTkFrame(self.root, corner_radius=5)
        MainControlFrame.place(
            anchor="nw", relx=0.65, rely=0.0, relwidth=1, relheight=1
        )

        ControlFrame = CTkFrame(MainControlFrame, corner_radius=5)
        ControlFrame.place(anchor="nw", relx=0.0, rely=0.0, relwidth=1, relheight=1)

        ClearButton = CTkButton(ControlFrame, text="Clear", command=self.clear_output)
        ClearButton.place(
            anchor="nw", relx=0.03, rely=0.05, relwidth=0.3, relheight=0.1
        )

        OutputButton = CTkButton(
            ControlFrame, text="print line cord", command=self.print_cord
        )
        OutputButton.place(
            anchor="nw", relx=0.03, rely=0.25, relwidth=0.3, relheight=0.1
        )

        OutPutFrame = CTkFrame(MainControlFrame, corner_radius=5, fg_color="gray")
        OutPutFrame.place(anchor="nw", relx=0.0, rely=0.4, relwidth=1, relheight=1)

        OutPutLabel = CTkLabel(
            OutPutFrame, text="OutPut", text_color="black", font=("Courier", 20, "bold")
        )
        OutPutLabel.place(anchor="nw", relx=0.03, rely=0, relwidth=0.3, relheight=0.1)

        self.OutPutTextbox = CTkTextbox(OutPutFrame)
        self.OutPutTextbox.place(
            anchor="nw", relx=0.015, rely=0.08, relwidth=0.32, relheight=0.5
        )
        self.OutPutTextbox.configure(state="disabled")

        ##########
        self.canvas = Canvas(canvasFrame, bg=self.OffColor)
        self.canvas.place(
            anchor="nw", relx=0.05, rely=0.1, relwidth=0.55, relheight=0.8
        )

        self.canvas.bind("<Motion>", self.DrawCord)
        self.canvas.bind("<Configure>", self.update_winfo)
        self.canvas.bind("<Button-1>", self.pixel_set)
        self.canvas.bind("<Button-3>", self.pixel_reset)

        self.root.mainloop()

    def clear_output(self):
        self.canvas.delete("all")
        self.lineflag = 0
        self.cordpoint.clear()
        self.OutPutTextbox.configure(state="normal")
        self.OutPutTextbox.delete("0.0", "end")
        self.OutPutTextbox.configure(state="disabled")
        self.update_winfo()

    def update_winfo(self, event="<Configure>", resize=True):
        if resize == True:
            self.canvas.delete("all")
            self.lineflag = 0
            self.cordpoint.clear()
            self.OutPutTextbox.configure(state="normal")
            self.OutPutTextbox.delete("0.0", "end")
            self.OutPutTextbox.configure(state="disabled")

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        for c in range(self.PixelWidth, self.GridWidth, self.PixelWidth):
            self.canvas.create_line(
                c,
                0,
                c,
                self.GridHeight,
                fill="white",
            )

        for r in range(self.PixelHeight, self.GridHeight, self.PixelHeight):
            self.canvas.create_line(
                0,
                r,
                self.GridWidth,
                r,
                fill="white",
            )

    def DrawLine(self, x0, y0, x1, y1, state=True):
        self.randcolor = "#" + secrets.token_hex(3)
        self.firstcolor = "#" + secrets.token_hex(3)
        firstflag = 1
        dx = x1 - x0
        dy = y1 - y0
        x_inc = 0
        y_inc = 0

        steps = max(abs(dx), abs(dy))  # number of steps needed

        if steps == 0:
            return

        if dx != 0 and steps != 0:
            x_inc = dx / steps
        if dy != 0 and steps != 0:
            y_inc = dy / steps

        x, y = x0, y0
        for _ in range(steps + 1):

            X = round(x)
            Y = round(y)

            if state:

                if firstflag:
                    self.canvas.create_rectangle(
                        (self.PixelWidth * X),
                        (self.PixelHeight * Y),
                        ((self.PixelWidth * X) + self.PixelWidth),
                        ((self.PixelHeight * Y) + self.PixelHeight),
                        fill=self.firstcolor,
                    )
                    firstflag = 0
                else:
                    self.canvas.create_rectangle(
                        (self.PixelWidth * X),
                        (self.PixelHeight * Y),
                        ((self.PixelWidth * X) + self.PixelWidth),
                        ((self.PixelHeight * Y) + self.PixelHeight),
                        fill=self.randcolor,
                    )
            else:

                self.canvas.create_rectangle(
                    (self.PixelWidth * X),
                    (self.PixelHeight * Y),
                    ((self.PixelWidth * X) + self.PixelWidth),
                    ((self.PixelHeight * Y) + self.PixelHeight),
                    fill=self.OffColor,
                )

            x += x_inc
            y += y_inc

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

        # self.update_winfo(resize=False)

    def print_line_cord(self):
        self.DrawLine(self.x0, self.y0, self.x1, self.y1)
        self.cordpoint.append(f"{{{self.x0}, {self.y0}, {self.x1}, {self.y1}}},")

    def print_cord(self):
        self.OutPutTextbox.configure(state="normal")
        self.OutPutTextbox.delete("0.0", "end")
        self.OutPutTextbox.configure(state="disabled")

        self.OutPutTextbox.configure(state="normal")

        try:
            self.update_winfo(resize=False)
            if self.lineflag == 0:

                for i in reversed(self.cordpoint):
                    if i == self.cordpoint[len(self.cordpoint) - 1]:
                        self.OutPutTextbox.insert("0.0", i.replace("},", "}") + "\n")

                    else:
                        self.OutPutTextbox.insert("0.0", i + "\n")

            else:
                messagebox.showwarning(
                    title="Line Warning", message="last line just has one point"
                )

        except:
            pass

        self.OutPutTextbox.configure(state="disabled")

    def pixel_set(self, event):

        if self.lineflag == 0:

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
            self.x0 = X
            self.y0 = Y
            self.lineflag = 1
            self.update_winfo(resize=False)
            return

        if self.lineflag == 1:

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

            self.x1 = X
            self.y1 = Y

            self.lineflag = 0
            self.print_line_cord()
            self.update_winfo(resize=False)
            return

    def pixel_reset(self, event):

        self.GridWidth = self.canvas.winfo_width()
        self.GridHeight = self.canvas.winfo_height()
        self.PixelWidth = int(self.canvas.winfo_width() / self.Width)
        self.PixelHeight = int(self.canvas.winfo_height() / self.Height)

        pcord = len(self.cordpoint)
        X = int(event.x / self.PixelWidth)
        Y = int(event.y / self.PixelHeight)

        if self.lineflag == 1:
            if self.x0 == X and self.y0 == Y:
                self.pixel = self.canvas.create_rectangle(
                    (self.PixelWidth * X),
                    (self.PixelHeight * Y),
                    ((self.PixelWidth * X) + self.PixelWidth),
                    ((self.PixelHeight * Y) + self.PixelHeight),
                    fill=self.OffColor,
                )
                self.update_winfo(resize=False)
                self.lineflag = 0

        if self.lineflag == 0:

            for cord in self.cordpoint:
                if cord[1] == str(X) and cord[4] == str(Y):
                    self.DrawLine(
                        int(cord[1]), int(cord[4]), int(cord[7]), int(cord[10]), False
                    )
                    self.cordpoint.remove(cord)

            if pcord != len(self.cordpoint):
                for cord in self.cordpoint:
                    self.DrawLine(
                        int(cord[1]), int(cord[4]), int(cord[7]), int(cord[10])
                    )

            self.update_winfo(resize=False)
            self.lineflag = 0


def main():

    main = Window()


if __name__ == "__main__":
    main()
