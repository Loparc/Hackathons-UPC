if memory.cosa != true {
memory.cosa = true;
memory.object = 0;
}

fn buscarw(x, y){
    for w in map.workers {


    }
}

for x in 0..40 {
    for y in 0..40 {
        if map[x][y] == Tile::EMPTY {
            // more logic
        }
        // other logic
    }
}

for w in 0..8 {
  if w == 4 && memory.object == 0 {
  memory.inix = worker(w).x;
  memory.iniy = worker(w).y;
  }

  if memory.object % 10 == 1 {
  let ni = (rand() % 4).abs();
  switch ni {
      0 => worker(w).move_up(),
      1 => worker(w).move_down(),
      2 => worker(w).move_right(),
      3 => worker(w).move_left(),
  }
  }
  else {
    if w % 2 == 0 && memory.object >= 250 && memory.object <= 300 {
      let difx = (memory.inix - worker(w).x).abs();
      let dify = (memory.iniy - worker(w).y).abs();
      if difx > dify {
      //movemos horizontal
        if memory.inix > worker(w).x {worker(w).move_right();}
        else {worker(w).move_left();}
      }
      else {
      //movemos vertical
      if memory.iniy > worker(w).y {worker(w).move_up();}
      else {worker(w).move_down();}
      }
    }
    else {
    let color = 0;
        if worker(w).color == Tile::RED {color = Tile::RED;}
        else if worker(w).color == Tile::GREEN {color = Tile::GREEN;}
        else if worker(w).color == Tile::BLUE {color = Tile::BLUE;}
        else {color = Tile::YELLOW;}  // yellow


        //we have the color

        let move = 0;
        let creu = 1;
        let x = worker(w).x;
        let y = worker(w).y;
        let pos = [0,0,0,0];
        while move == 0 {

          //analizamos que direcciones estan a distancia "creu"

          //abajo
          if  y-creu >= 0 && y >= 1 && map[x][y-creu] != color {pos[0] = 1; move = 1;}
          //izq
          if x-creu >= 0 && x >= 1 && map[x-creu][y] != color {pos[1] = 1; move = 1;}
          //up
          if y+creu <= 39 && y <= 38 && map[x][y+creu] != color {pos[2] = 1; move = 1;}
          //right
          if x+creu <= 39 && x <= 38 && map[x+creu][y] != color {pos[3] = 1; move = 1;}
          else {creu = creu + 1;}
          }
        let sum = pos[0] + pos[1] + pos[2] + pos[3];

        //random para decidir
        let r = 0;
        let moved = 0;

        //pos[0,1,1,0]

        while moved == 0 {
          r = (rand() % 4).abs();

          switch r {
            0 => if pos[r] == 1 {worker(w).move_down(); moved = 1;},
            1 => if pos[r] == 1 {worker(w).move_left(); moved = 1;},
            2 => if pos[r] == 1 {worker(w).move_up(); moved = 1;},
            3 => if pos[r] == 1 {worker(w).move_right(); moved = 1;},
          }
        }
      }
    }


    //print (memory.object);

  //if w == 6 {print(memory.inix); print(memory.iniy);}
    info(`worker ${w} finished`);
}
memory.object +=1;
