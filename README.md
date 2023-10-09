# FdF
> This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines..
<p align="center">
	<img src="https://github.com/Tnantaki/FDF/blob/master/images/julia_map.png" />
	<img src="https://github.com/Tnantaki/FDF/blob/master/images/t1_map.png" />
</p>

---
## 📝Usage
### 1. Requirement
if you run on Linux. Install `x11` by following command.
```bash
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
### 2. Compilation
To compile the program, run `make` on **FdF** directory.
```bash
$ make
```
### 3. Execution
The program takes 1 argument (map) to execute. run:
```bash
$ ./fdf test_maps/map.rt
```
## 🎮Key Controls
|Key|Action|
|---|---|
|`ESC`|close the program|
|`W` or `🡡`|move object up|
|`A` or `🡠`|move object to the left|
|`S` or `🡣`|move object down|
|`D` or `🡢`|move object to the right|
|`+`|Zoom in|
|`-`|Zoom out|

## 📑 Documentation 
* [miniLibx Doc](https://harm-smits.github.io/42docs/libs/minilibx)
