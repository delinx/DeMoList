===============
DML - DeMoList
===============

Information
======

Concept
-----------

**DML** is a server side self sufficient CS:GO demo manager with a web interface, it can check FTP server for new .dem files, download and parse them, generate list of matches and match specific shareable links allowing to share demos with the other team easily.


Development
======

Modules
-----------
* Simple web server to be used with reverse proxy (*Apache / Nginx / etc*)
* Web interface
* FTP demo downloader
* .dem parser (no POV demo support, only server side demos)
* Generation of long term and per match statistics of players
* Generating sharable links to match pages allowing .dem download
* **No authentication or encryption systems are provided, use reverse proxy**

Notice
-----------
The goal is to write most of this project using C, this is a learning project for me and something I could actually use in day to day. I fully acknowledge this can be more easily accomplished using existing Go or JS demo parser with simple web interface on top and FTP module.

Tools you could use to accomplish this: 

* (Node)   https://github.com/saul/demofile
* (Go)     https://github.com/markus-wa/demoinfocs-golang
* (Python) https://github.com/pnxenopoulos/awpy

So please no "Why are you not using X instead", make your own project. 

License
======
::

	MIT License

	DML - DeMoList

	Copyright © 2022 Mihails 'Delinx' Mozajevs

	Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
