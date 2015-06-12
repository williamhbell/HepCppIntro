# TARGETS:
# make           -- build PostScript version of paper
# make view      -- build PS version + show it using gv
# make print     -- build PS version and send to default printer
# make clean     -- remove all but PS file
# make veryclean -- removes all generated files


# Known Bugs
# If $(TARGET).fig changes, bbl file is rebuild unnecessarily


TARGET=HepCppIntroGuide

TEX=$(TARGET).tex
BIB=$(TARGET).bib
BBL=$(TARGET).bbl
DVI=$(TARGET).dvi
AUX=$(TARGET).aux
BLG=$(TARGET).blg
BACKUP=*~

GV=gv
LPR=lpr

PDF=$(TARGET).pdf
PS=$(TARGET).ps

GFX=

LATEX_DEPENDENCIES=$(GFX)

paper: $(PDF)

view: paper
	$(GV) $(PS)

print: paper
	$(LPR) $(PS)

$(DVI): $(TEX) $(BBL) $(LATEX_DEPENDENCIES)
	@echo "**"
	@echo "**"
	@echo "** Building DVI file"
	@echo "**"
	@echo "**"
	latex $(TARGET)
	latex $(TARGET)
# This is a cheat to stop rebuilding the BBL just because we run LaTeX
	touch $(BBL)

clean:
	@rm -f $(DVI) $(AUX) $(BBL) $(TARGET).log $(TARGET).toc $(BLG) $(BACKUP)

veryclean: clean
	@rm -f $(PS)
	@rm -f $(PDF)

$(BBL): $(AUX) $(BIB) 
	@echo "**"
	@echo "**"
	@echo "** Building BBL file"
	@echo "**"
	@echo "**"
	bibtex $(TARGET)

%.aux: %.tex $(LATEX_DEPENDENCIES)
	@echo "**"
	@echo "**"
	@echo "** Generating AUX file"
	@echo "**"
	@echo "**"
	latex $<

%.ps: %.dvi
	@echo "**"
	@echo "**"
	@echo "** DVI file -> PS file"
	@echo "**"
	@echo "**"
	dvips -Ppdf -ta4 $< -o

%.pdf: %.ps
	@echo "**"
	@echo "**"
	@echo "** PS file -> PDF file"
	@echo "**"
	@echo "**"
	ps2pdf $<

%.eps: %.fig
	@echo "**"
	@echo "**"
	@echo "** Building figure $@"
	@echo "**"
	@echo "**"
	fig2dev -L eps $< > $@
