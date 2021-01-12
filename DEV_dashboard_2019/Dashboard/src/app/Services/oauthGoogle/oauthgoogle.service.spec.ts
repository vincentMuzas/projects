import { TestBed } from '@angular/core/testing';

import { OauthgoogleService } from './oauthgoogle.service';

describe('OauthgoogleService', () => {
  let service: OauthgoogleService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(OauthgoogleService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
