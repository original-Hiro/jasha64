-- Copyright 1986-2015 Xilinx, Inc. All Rights Reserved.
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity PD is
  Port ( 
    a : in STD_LOGIC_VECTOR ( 3 downto 0 );
    p : out STD_LOGIC;
    d : out STD_LOGIC
  );

end PD;

architecture stub of PD is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
begin
end;
