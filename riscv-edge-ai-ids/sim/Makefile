all: clean compile run

compile:
	mkdir -p sim_build
	iverilog -g2012 -o sim_build/sim.vvp testbench.v ../hardware/rtl/accelerator.v

run:
	vvp sim_build/sim.vvp

clean:
	rm -rf sim_build *.vvp *.vcd