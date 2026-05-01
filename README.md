<p align="center">
  <img src="https://img.icons8.com/color/96/000000/route.png" alt="ruta" width="80"/>
</p>

<h1 align="center">🚛 Sistema Inteligente de Gestión Logística y Optimización de Rutas</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue?logo=c%2B%2B" alt="C++">
  <img src="https://img.shields.io/badge/Algoritmo-Dijkstra-orange?logo=graphql" alt="Dijkstra">
  <img src="https://img.shields.io/badge/Estructura-Grafo_(Matriz_Adyacencia)-purple" alt="Grafo">
  <img src="https://img.shields.io/badge/Desarrollo-En_progreso-yellow" alt="Estado">
  <img src="https://img.shields.io/badge/Licencia-MIT-green" alt="Licencia">
</p>

---

## 📋 **Descripción del Proyecto**
Aplicación de escritorio para la **gestión de redes logísticas** en la provincia de **Córdoba**, Argentina.  
Permite administrar ciudades, rutas y calcular el **camino más corto** entre dos nodos, incluso si alguna ruta es **cortada o inhabilitada temporalmente**.

---

## 🏫 **Datos Académicos**

| 🎓 Institución | 📚 Materia | 👨‍🏫 Docente | 📅 Ciclo |
|----------------|------------|-------------|----------|
| Universidad Provincial de Ezeiza (UPE) | Estructura de Datos y Algoritmos II | Osvaldo Pini | 2026 |

| 👥 Integrantes |
|----------------|
| Bertera Lautaro |
| Gomez Ornella  |
| Juan Y|
| Pol Y |


---

## 🗺️ **Provincia y Ciudades Modeladas**
### 📍 **Córdoba**
Se seleccionaron **5 nodos estratégicos** con distancias entre 200 km y 300 km en su mayoría.

| ID | Ciudad | Rol |
|----|--------|-----|
| 0  | Córdoba Capital | Nodo Central / Origen |
| 1  | Río Cuarto | Sur |
| 2  | San Francisco | Este |
| 3  | Villa Dolores | Oeste / Traslasierra |
| 4  | Huinca Renancó | Extremo Sur |

---

## 🚚 **Rutas Relevadas (Distancias Aproximadas)**
| Origen ↔ Destino | Distancia | Ruta |
|------------------|-----------|------|
| Córdoba ↔ Río Cuarto | 215 km | RN36 |
| Córdoba ↔ Villa Dolores | 210 km | Cam. Altas Cumbres |
| Córdoba ↔ Huinca Renancó | 410 km | Opcional |
| San Francisco ↔ Río Cuarto | 260 km | RN158 |
| Río Cuarto ↔ Huinca Renancó | 200 km | RN35 |

---

## 🧮 **Matriz de Adyacencia**
La siguiente imagen muestra la tabla de distancias usada por el algoritmo.  
`INF` = sin conexión directa, `0` = mismo nodo.

<p align="center">
  <a href="https://ibb.co/TqTM6dbm" target="_blank">
    <img src="https://i.ibb.co/... (reemplazar con enlace directo a la imagen)" alt="Matriz de Adyacencia" width="500"/>
  </a>
  <br/>
  <sub>⚠️ Para ver la imagen incrustada correctamente, subí la captura a <a href="https://imgbb.com">imgbb</a> y usá el enlace directo (hotlink).</sub>
</p>

---

## ⚙️ **Características Técnicas**
- **Lenguaje:** C++
- **Estructura de datos:** Matriz de adyacencia estática (`int matriz[5][5]`)  
- **Algoritmo principal:** Dijkstra (búsqueda del camino más corto)  
- **Manejo de contingencias:** Corte temporal de rutas asignando `INF`  
- **Persistencia:** Archivos binarios para guardar configuración e historial  
- **Interfaz gráfica:** Componentes TImage, TComboBox, TStringGrid, TButton (VCL / C++ Builder)

---

## ▶️ **Cómo Ejecutar**
1. Cloná el repositorio:  
   `git clone https://github.com/tu-usuario/tp-eda2.git`
2. Abrí el proyecto en **C++ Builder** (o compilador compatible con VCL).
3. Compilá y ejecutá el archivo `main.cpp`.
4. Cargá ciudades, definí rutas y presioná **Calcular**.

---

## 🧪 **Funcionalidades**
- ✔️ Alta, baja y modificación de ciudades (con coordenadas X, Y).
- ✔️ Definición de rutas con distancia en km.
- ✔️ Visualización de nodos y aristas sobre mapa de fondo.
- ✔️ Cálculo de ruta óptima con **Dijkstra**.
- ✔️ **Corte de ruta** y recálculo automático de alternativas.
- ✔️ Guardado y carga de datos en archivo binario.
- ✔️ Historial de operaciones realizadas.

---

## 📄 **Licencia**
Este proyecto se distribuye bajo la Licencia MIT. Ver archivo `LICENSE` para más detalles.

---

<p align="center">
  Hecho con ❤️ y mucho ☕ por el equipo de EDA2 – 2026
</p>
