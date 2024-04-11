"""
Roteiro 1 - Computação Gráfica
Paulo Araujo - 665497
"""

import tkinter as tk
import math

class Interface:
    def __init__(self, janela):

        # Janela principal
        self.janela = janela
        self.janela.title("Computação Gráfica")
        
        # Criação janela 
        self.canvas = tk.Canvas(self.janela, width=1000, height=700, bg="white")
        self.canvas.pack(side=tk.LEFT)
        
        # Criação frame
        self.button_frame = tk.Frame(self.janela)
        self.button_frame.pack(side=tk.RIGHT, padx=10)
        
        # Botão Reta BRE
        self.ln_button = tk.Button(self.button_frame, text="Reta BRE", command=self.reta)
        self.ln_button.pack(pady=5)

        # Botão Reta DDA
        self.ln_dda_button = tk.Button(self.button_frame, text="Reta DDA", command=self.reta)
        self.ln_dda_button.pack(pady=5)
        
        # Botão Círculo
        self.circle_button = tk.Button(self.button_frame, text="Círculo", command=self.circulo)
        self.circle_button.pack(pady=5)
        
        # Botão Polígono
        self.poligon_button = tk.Button(self.button_frame, text="Polígono", command=self.poligon)
        self.poligon_button.pack(pady=5)

        # Botão Recorte
        self.clip_button = tk.Button(self.button_frame, text="Recorte", command=self.clip_objects)
        self.clip_button.pack(pady=5)

        # Label para deslocamento horizontal
        self.dx_label = tk.Label(self.button_frame, text="dx:")
        self.dx_label.pack()
        self.dx_entry = tk.Entry(self.button_frame)
        self.dx_entry.pack()

        # Label para deslocamento vertical
        self.dy_label = tk.Label(self.button_frame, text="dy:")
        self.dy_label.pack()
        self.dy_entry = tk.Entry(self.button_frame)
        self.dy_entry.pack()

        # Label para rotação
        self.angle_label = tk.Label(self.button_frame, text="Ângulo de Rotação:")
        self.angle_label.pack()
        self.angle_entry = tk.Entry(self.button_frame)
        self.angle_entry.pack()

        # Label para o fator X
        self.scale_x_label = tk.Label(self.button_frame, text="Fator de Escala X:")
        self.scale_x_label.pack()
        self.scale_x_entry = tk.Entry(self.button_frame)
        self.scale_x_entry.pack()

        # Label para o fator Y
        self.scale_y_label = tk.Label(self.button_frame, text="Fator de Escala Y:")
        self.scale_y_label.pack()
        self.scale_y_entry = tk.Entry(self.button_frame)
        self.scale_y_entry.pack()

        # Opções de reflexão
        self.reflect_x_var = tk.IntVar()
        self.reflect_x_checkbox = tk.Checkbutton(self.button_frame, text="Reflexão X", variable=self.reflect_x_var)
        self.reflect_x_checkbox.pack()
        self.reflect_y_var = tk.IntVar()
        self.reflect_y_checkbox = tk.Checkbutton(self.button_frame, text="Reflexão Y", variable=self.reflect_y_var)
        self.reflect_y_checkbox.pack()
        self.reflect_xy_var = tk.IntVar()
        self.reflect_xy_checkbox = tk.Checkbutton(self.button_frame, text="Reflexão XY", variable=self.reflect_xy_var)
        self.reflect_xy_checkbox.pack()

        # Botão Translação
        self.translate_button = tk.Button(self.button_frame, text="Translação", command=self.translate)
        self.translate_button.pack(pady=5)

        # Botão Rotação
        self.rotate_button = tk.Button(self.button_frame, text="Rotação", command=self.rotate)
        self.rotate_button.pack(pady=5)

        # Botão Escala
        self.scale_button = tk.Button(self.button_frame, text="Escala", command=self.scale)
        self.scale_button.pack(pady=5)

        # Botão Reflexão
        self.reflect_button = tk.Button(self.button_frame, text="Reflexão", command=self.reflect)
        self.reflect_button.pack(pady=5)

        # Botão Reflexão
        self.clean_button = tk.Button(self.button_frame, text="LIMPAR", command=self.clean)
        self.clean_button.pack(pady=5)

        # Variáveis de início e fim
        self.current_tool = None
        self.start_point = None
        self.end_point = None
        self.poligon_points = []
        self.clip_mode = False
        self.clip_rect = None

        # Definir clique do mouse
        self.canvas.bind("<Button-1>", self.mouse_click)

    # Método "Reta"
    def reta(self):
        self.current_tool = "Reta"

    # Método "Círculo"
    def circulo(self):
        self.current_tool = "Círculo"

    # Método "Polígono"
    def poligon(self):
        self.current_tool = "Polígono"
        self.poligon_points = []
        self.draw_poligon()

    # Método "Recorte"
    def recorte(self):
        # Definir a ferramenta atual como "Recorte"
        self.current_tool = "Recorte"

        # Capturar os dois pontos clicados pelo usuário para definir a região de recorte
        self.canvas.bind("<Button-1>", self.capturar_ponto_inicial)

    def capturar_ponto_inicial(self, event):
        # Capturar as coordenadas do primeiro ponto
        self.x1 = event.x
        self.y1 = event.y

        # Atualizar o evento para capturar o segundo ponto
        self.canvas.bind("<Button-1>", self.capturar_ponto_final)

    def capturar_ponto_final(self, event):
        # Capturar as coordenadas do segundo ponto
        self.x2 = event.x
        self.y2 = event.y

        # Realizar o recorte
        self.clip_objects()

    def clip_objects(self):
        # Implementar a lógica de recorte usando as coordenadas x1, y1, x2, y2

        # Resetar o comportamento do clique do mouse para não interferir com outras operações
        self.canvas.unbind("<Button-1>")

        # Resetar a ferramenta atual
        self.current_tool = None

    ##TRANSLAÇÃO, ROTAÇÃO, ESCALA, REFLEXÃO## 

    # Método translação
    def translate(self):
        dx = int(self.dx_entry.get())
        dy = int(self.dy_entry.get())

        # Move o objeto
        for item in self.canvas.find_all():
            self.canvas.move(item, dx, dy)

    # Método rotação 
    def rotate(self):
        angle_degrees = float(self.angle_entry.get())
        angle_radians = math.radians(angle_degrees)  #Convertendo radianos

        # Calcular ponto médio
        bbox = self.canvas.bbox("all")
        center_x = (bbox[0] + bbox[2]) / 2
        center_y = (bbox[1] + bbox[3]) / 2

        # Rotacionar
        for item in self.canvas.find_all():
            coords = self.canvas.coords(item)
            new_coords = []

            for i in range(0, len(coords), 2):
                x = coords[i]
                y = coords[i + 1]
                x_new = center_x + (x - center_x) * math.cos(angle_radians) - (y - center_y) * math.sin(angle_radians)
                y_new = center_y + (x - center_x) * math.sin(angle_radians) + (y - center_y) * math.cos(angle_radians)
                new_coords.extend([x_new, y_new])

            self.canvas.coords(item, *new_coords)

    # Método escala
    def scale(self):
        scale_x = float(self.scale_x_entry.get())
        scale_y = float(self.scale_y_entry.get())

        # Calcular ponto médio
        bbox = self.canvas.bbox("all")
        center_x = (bbox[0] + bbox[2]) / 2
        center_y = (bbox[1] + bbox[3]) / 2

        # Escalonar
        for item in self.canvas.find_all():
            coords = self.canvas.coords(item)
            new_coords = []

            for i in range(0, len(coords), 2):
                x = coords[i]
                y = coords[i + 1]
                x_new = center_x + (x - center_x) * scale_x
                y_new = center_y + (y - center_y) * scale_y
                new_coords.extend([x_new, y_new])

            self.canvas.coords(item, *new_coords)
    
    # Método reflexão
    def reflect(self):
        reflect_x = self.reflect_x_var.get()
        reflect_y = self.reflect_y_var.get()
        reflect_xy = self.reflect_xy_var.get()

        # Reflexão nos eixos X, Y e XY
        if reflect_x:
            for item in self.canvas.find_all():
                self.canvas.scale(item, 0, 0, 1, -1)
        if reflect_y:
            for item in self.canvas.find_all():
                self.canvas.scale(item, 0, 0, -1, 1)
        if reflect_xy:
            for item in self.canvas.find_all():
                self.canvas.scale(item, 0, 0, -1, -1)

    def clean(self):
        self.canvas.delete("all")

    ##BRESENHAM E DDA##

    # Método Reta Bresenham
    def draw_line(self, start_point, end_point):
        x1, y1 = start_point
        x2, y2 = end_point

        dx = abs(x2 - x1)
        dy = abs(y2 - y1)
        sx = 1 if x1 < x2 else -1
        sy = 1 if y1 < y2 else -1

        if dx > dy:
            err = dx / 2

            while x1 != x2:
                self.canvas.create_line(x1, y1, x1 + 1, y1 + 1, fill="black")
                err -= dy
                if err < 0:
                    y1 += sy
                    err += dx
                x1 += sx
        else:
            err = dy / 2

            while y1 != y2:
                self.canvas.create_line(x1, y1, x1 + 1, y1 + 1, fill="black")
                err -= dx
                if err < 0:
                    x1 += sx
                    err += dy
                y1 += sy
        self.canvas.create_line(x1, y1, x2, y2, fill="black")

    # Método Reta DDA
    def draw_line_dda(self, start_point, end_point):
        x1, y1 = start_point
        x2, y2 = end_point

        # Calcular as diferenças de coordenadas
        dx = x2 - x1
        dy = y2 - y1

        # Determinar o número de passos necessários
        steps = max(abs(dx), abs(dy))

        # Calcular o incremento em x e y para cada passo
        if steps != 0:
            increment_x = dx / steps
            increment_y = dy / steps
        else:
            increment_x, increment_y = 0, 0

        # Desenhar a linha
        x, y = x1, y1
        for _ in range(steps):
            self.plot_point(round(x), round(y))
            x += increment_x
            y += increment_y

    ##BRESENHAM##
        
    # Método para desenhar um círculo definido por dois pontos
    def draw_circle(self, start_point, end_point):
        center_x = (start_point[0] + end_point[0]) // 2
        center_y = (start_point[1] + end_point[1]) // 2
        radius = ((end_point[0] - start_point[0]) ** 2 + (end_point[1] - start_point[1]) ** 2) ** 0.5 / 2

        self.plot_circle(center_x, center_y, radius)

    # Método para plotar pontos da circunferência
    def plot_circle(self, center_x, center_y, radius):
        x = radius
        y = 0
        d = 1 - radius

        while x >= y:
            self.plot_point(center_x + x, center_y + y)
            self.plot_point(center_x - x, center_y + y)
            self.plot_point(center_x + x, center_y - y)
            self.plot_point(center_x - x, center_y - y)
            self.plot_point(center_x + y, center_y + x)
            self.plot_point(center_x - y, center_y + x)
            self.plot_point(center_x + y, center_y - x)
            self.plot_point(center_x - y, center_y - x)

            y += 1
            if d <= 0:
                d += 2 * y + 1
            else:
                x -= 1
                d += 2 * (y - x) + 1

    # Método desenhar um ponto
    def plot_point(self, x, y):
        self.canvas.create_rectangle(x, y, x, y, fill="black")

    ##COHEN_SUTHERLAND##

    # Método recortar linha - Cohen-Sutherland
    def cohen_sutherland(self, x1, y1, x2, y2, x_min, y_min, x_max, y_max):
        # Definir os códigos de recorte para os pontos iniciais e finais da linha
        code1 = self.calculate_outcode(x1, y1, x_min, y_min, x_max, y_max)
        code2 = self.calculate_outcode(x2, y2, x_min, y_min, x_max, y_max)

        # Loop até que a linha esteja completamente dentro da janela de recorte ou completamente fora
        while True:
            # Se ambos os códigos de recorte forem 0, a linha está completamente dentro
            if code1 == 0 and code2 == 0:
                return x1, y1, x2, y2  # Retorna as coordenadas originais da linha

            # Se houver uma interseção, a linha está completamente fora
            if code1 & code2 != 0:
                return None  # Retorna None indicando que a linha está completamente fora

            # Escolha um ponto fora da janela de recorte
            if code1 != 0:
                code_out = code1
            else:
                code_out = code2

            # Encontre a interseção do ponto externo com os limites da janela de recorte
            if code_out & 1:
                x_new = x_min
                y_new = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1)
            elif code_out & 2:
                x_new = x_max
                y_new = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1)
            elif code_out & 4:
                y_new = y_min
                x_new = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1)
            elif code_out & 8:
                y_new = y_max
                x_new = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1)

            # Atualize o ponto externo com as novas coordenadas calculadas
            if code_out == code1:
                x1, y1 = x_new, y_new
                code1 = self.calculate_outcode(x1, y1, x_min, y_min, x_max, y_max)
            else:
                x2, y2 = x_new, y_new
                code2 = self.calculate_outcode(x2, y2, x_min, y_min, x_max, y_max)

    # Método para calcular o código de recorte de um ponto
    def calculate_outcode(self, x, y, x_min, y_min, x_max, y_max):
        code = 0
        if x < x_min:
            code |= 1
        elif x > x_max:
            code |= 2
        if y < y_min:
            code |= 4
        elif y > y_max:
            code |= 8
        return code

    # Método desenhar linha recortada
    def draw_clipped_line(self, start_point, end_point):
        x1, y1 = start_point
        x2, y2 = end_point
        x_min, y_min, x_max, y_max = 100, 100, 900, 600  # Define os limites da área de recorte

        # Realiza o recorte
        clipped_points = self.cohen_sutherland(x1, y1, x2, y2, x_min, y_min, x_max, y_max)

        # Desenha a linha recortada se não estiver completamente fora
        if clipped_points:
            x1_clipped, y1_clipped, x2_clipped, y2_clipped = clipped_points
            self.canvas.create_line(x1_clipped, y1_clipped, x2_clipped, y2_clipped, fill="red")

    # Adicione uma variável para armazenar os pontos do retângulo de recorte
        self.clip_rect = None

    def mouse_click(self, event):
        if self.current_tool == "Polígono":
            self.poligon_points.append((event.x, event.y))
            self.draw_poligon()
        elif self.current_tool == "Reta":
            if self.start_point is None:
                self.start_point = (event.x, event.y)
            else:
                self.end_point = (event.x, event.y)
                self.draw_line(self.start_point, self.end_point)
                self.start_point = None
                self.end_point = None
        elif self.current_tool == "Círculo":
            if self.start_point is None:
                self.start_point = (event.x, event.y)
            else:
                self.end_point = (event.x, event.y)
                self.draw_circle(self.start_point, self.end_point)
                self.start_point = None
                self.end_point = None
        elif self.current_tool == "Recorte":
            if self.clip_rect is None:
                self.clip_rect = [(event.x, event.y)]
            else:
                self.clip_rect.append((event.x, event.y))
                self.clip_objects()
                self.clip_rect = None


    # Método para desenhar polígono
    def draw_poligon(self):
        self.canvas.delete("poligon")  

        if len(self.poligon_points) > 1:
            self.canvas.create_line(self.poligon_points, fill="black", tags="poligon")
            
        if self.current_tool == "Polígono" and len(self.poligon_points) > 2:
            self.canvas.create_line(self.poligon_points[-1], self.poligon_points[0], fill="black", tags="poligon")

        for point in self.poligon_points:
            self.canvas.create_oval(point[0]-2, point[1]-2, point[0]+2, point[1]+2, fill="black")

    # Método para recortar objetos dentro do retângulo de recorte
    def clip_objects(self):
        if self.clip_rect is not None and len(self.clip_rect) == 2:
            # Obter as coordenadas dos dois pontos clicados
            x1, y1 = self.clip_rect[0]
            x2, y2 = self.clip_rect[1]
            
            # Calcular os limites do retângulo
            x_min = min(x1, x2)
            y_min = min(y1, y2)
            x_max = max(x1, x2)
            y_max = max(y1, y2)
            
            items_to_delete = []
            for item in self.canvas.find_all():
                bbox = self.canvas.bbox(item)
                # Verifica se o objeto está fora da área de recorte
                if bbox[0] > x_max or bbox[1] > y_max or bbox[2] < x_min or bbox[3] < y_min:
                    items_to_delete.append(item)
            for item in items_to_delete:
                self.canvas.delete(item)

root = tk.Tk()
app = Interface(root)
root.mainloop()