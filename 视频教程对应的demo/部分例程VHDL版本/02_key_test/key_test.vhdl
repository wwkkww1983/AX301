library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_signed.all;

entity key_test is
  port ( 
    clk    : in std_logic;
    key_in : in std_logic_vector(3 downto 0);
    led_out    : out std_logic_vector(3 downto 0)
	 );
end entity key_test;

architecture rtl of key_test is
signal led_r: std_logic_vector(3 downto 0);
signal led_r1: std_logic_vector(3 downto 0);
begin
	process(clk) is
	begin
		if clk'event and clk = '1' then
			led_r1 <= led_r;
		end if;
	end process;
	
	process(clk) is
	begin
		if clk'event and clk = '1' then
			led_r <= not key_in;
		end if;			
	end process;	
	led_out <= led_r1;
end architecture rtl;
