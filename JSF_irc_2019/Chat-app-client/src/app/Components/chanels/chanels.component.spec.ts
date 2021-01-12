import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ChanelsComponent } from './chanels.component';

describe('ChanelsComponent', () => {
  let component: ChanelsComponent;
  let fixture: ComponentFixture<ChanelsComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ChanelsComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ChanelsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
